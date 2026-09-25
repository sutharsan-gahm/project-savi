# Project SAVI - Hardware Documentation

This directory contains the open hardware schematics, pin mappings, and bill of materials (BOM) under the CERN-OHL-P v2 license.

## 1. System Architecture & Pin Mapping (ESP32)

| Component | Interface / Pin | Operating Voltage | Function |
| :--- | :--- | :--- | :--- |
| **MPU6050** | I2C (SDA: GPIO 21, SCL: GPIO 22) | 3.3V | Agitation & Tremor Detection |
| **DRV2605L** | I2C (SDA: GPIO 21, SCL: GPIO 22) | 3.3V | Haptic Driver Controller |
| **LRA Actuator (10mm)** | Differential OUT+ / OUT- (DRV2605L) | Driven by IC | Somatosensory Haptic Actuation |
| **Analog Mic** | ADC (GPIO 34) | 3.3V | Voice Spectrum Sampling (85–255 Hz) |
| **Power Switch** | Micro SPST Inline | Battery VDD | Hardware Safety Cut-off |

## 2. Target Bill of Materials ($15 BOM)
* ESP32 Dual-Core Dev Module: $3.50
* MPU6050 Accelerometer/Gyroscope: $1.20
* DRV2605L Haptic Driver IC: $2.10
* 10mm Linear Resonant Actuator (LRA): $1.80
* Analog Microphone / Pre-amp: $1.00
* Power Management & Li-Po / 3.3V LDO: $2.40
* IP67 Enclosure & Passive Components: $3.00
* **Total Target BOM:** ~$15.00
​## 3. Hardware Block Diagram & Electrical Wiring Schematics

```text
               +-------------------------------------------------------------+
               |                  3.7V Li-Po Battery (500mAh)                |
               +------------------------------+------------------------------+
                                              |
                                     [SPST Safety Cut-off]
                                              |
                                              v
               +-------------------------------------------------------------+
               |              3.3V Ultra-Low Dropout (LDO) Regulator         |
               +------------------------------+------------------------------+
                                              | (VCC 3.3V & GND Bus)
     +----------------------------------------+----------------------------------------+
     |                                        |                                        |
     v                                        v                                        v
+----------+                             +----------+                             +----------+
|  Analog  |                             |          |                             |          |
|  Mic +   |                             | MPU-6050 |                             | DRV2605L |
| Pre-Amp  |                             |  (IMU)   |                             | (Haptic) |
+----+-----+                             +----+-----+                             +----+-----+
     | (Audio Out)                            |                                        |
     |                                        | (I2C Bus: SDA=GPIO 21, SCL=GPIO 22)    |
     v                                        +-------------------+--------------------+
[GPIO 34 / ADC]                                                   |
     |                                                            v
     |         +------------------------------------------------------------------+
     +-------->|                      ESP32 Dual-Core MCU                         |
               |                                                                  |
               |  [Core 0: Agitation Telemetry]     [Core 1: DSP / FFT Analysis]  |
               |  • Reads MPU-6050 Accelerometer    • Samples Audio (85–255 Hz)   |
               |  • Computes Tremor Index           • Maps to Pacinian Resonance  |
               |  • Closed-Loop Trigger Logic       • Sends I2C Control to Driver |
               +------------------------------------------------------------------+
                                                                  |
                                                                  | (Differential OUT+ / OUT-)
                                                                  v
                                              +---------------------------------------+
                                              |       10mm Linear Resonant Actuator   |
                                              |        (LRA Somatosensory Pulse)      |
                                              +---------------------------------------+
4. Acoustic-to-Tactile Signal Transformation Pipeline+--------------------------------------------------------------------------------------+
| 1. ACOUSTIC CAPTURE                                                                  |
|    Human Vocal Spectrum: 85 Hz – 255 Hz (Fundamental frequencies of familiar voice)  |
+------------------------------------------+-------------------------------------------+
                                           |
                                           v
+--------------------------------------------------------------------------------------+
| 2. EDGE-DSP COMPUTATION (ESP32 Core 1)                                               |
|    • Dynamic 128-point Fast Fourier Transform (FFT) on ADC (GPIO 34)                 |
|    • Noise Gate Filtration: Suppresses non-vocal ambient environmental noise         |
|    • Frequency Transduction Function: Linear mapping f(voice) -> f(haptic)           |
+------------------------------------------+-------------------------------------------+
                                           |
                                           v
+--------------------------------------------------------------------------------------+
| 3. PACINIAN RESONANT MAPPING                                                         |
|    Target Band: 150 Hz – 300 Hz (Optimal cutaneous mechanoreceptor response band)   |
+------------------------------------------+-------------------------------------------+
                                           |
                                           v
+--------------------------------------------------------------------------------------+
| 4. CLOSED-LOOP ACTUATION (DRV2605L + 10mm LRA)                                       |
|    • Real-time I2C Register Writes from Core 1                                       |
|    • Generates micro-vibrational somatosensory pulse-train                           |
+------------------------------------------+-------------------------------------------+
                                           |
                                           v
+--------------------------------------------------------------------------------------+
| 5. NEURO-SOMATIC ANCHORING (Human Receptor Layer)                                    |
|    Dermal Pacinian Corpuscles -> Somatosensory Pathway -> Hippocampus & Amygdala     |
|    Outcome: Non-verbal presence simulation & cognitive load down-regulation           |
+--------------------------------------------------------------------------------------+
