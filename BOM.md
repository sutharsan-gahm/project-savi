# Project SAVI - Bill of Materials (BOM) & Hardware Specs

**Target Cost:** ~$15.00 USD (Frugal Innovation Target)  
**Open Hardware Standard:** CERN-OHL-P v2 Compliance  

---

| Component | Description | Qty | Est. Unit Cost (USD) | Primary Function |
| :--- | :--- | :---: | :---: | :--- |
| **ESP32 NodeMCU** | Dual-Core 240MHz Microcontroller (Wi-Fi/BT) | 1 | $3.50 | Core DSP Processing & Sensor Sampling |
| **DRV2605L** | Haptic Driver Board (I2C Controller) | 1 | $2.20 | LRA Actuator Waveform Generation |
| **MPU6050** | 6-Axis Accelerometer / Gyroscope Module | 1 | $1.20 | Mechanical Noise & Spatial Sensing |
| **Linear Resonant Actuator** | LRA Vibration Motor (150-300 Hz) | 1 | $1.80 | Targeted Somatosensory ANC Output |
| **Micro-Turbine Escapement** | Passive Mechanical Transducer | 1 | $2.50 | Ambient Kinetic Energy Harvesting (Part 3) |
| **Power Switch & Case** | SPST Safety Kill-Switch + 3D Chassis | 1 | $1.50 | Hardware Privacy & Structural Enclosure |
| **LiPo Battery / Passive** | 3.7V Power Cell / Direct Fluid Intake | 1 | $2.30 | System Power Source |
| **Total Target Cost** | **Frugal Architecture Assembly** | - | **~$14.50 USD** | **Full Functional Prototyping** |

---

## Hardware Compliance Notes
* **Zero-Telemetry:** SPST physical kill-switch cuts VCC directly to prevent remote data logging.
* **Component Sourcing:** All ICs and modules are readily available off-the-shelf to promote global decentralization and reproducible manufacturing.
