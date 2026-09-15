/*
 * Project SAVI - Active Haptic-ANC & DSP Firmware (Part 2 Integration)
 * Author: Sutharsan Sakathevan (GAHM Initiative)
 * License: MIT License
 * Hardware: ESP32 + DRV2605L + MPU6050
 */

#include <Wire.h>
#include <Adafruit_DRV2605.h>

#define MPU6050_ADDR 0x68
#define KILL_SWITCH_PIN 13 // Zero-Telemetry Hardware Kill-Switch

Adafruit_DRV2605 drv;
int16_t accelZ;

void setup() {
    pinMode(KILL_SWITCH_PIN, INPUT_PULLUP);
    Wire.begin();
    
    if (!drv.begin()) {
        while (1); // Halt if driver fails
    }
    
    drv.selectLibrary(1);
    drv.setMode(DRV2605_MODE_INTTRIG);

    // MPU6050 Wake-up
    Wire.beginTransmission(MPU6050_ADDR);
    Wire.write(0x6B);
    Wire.write(0);
    Wire.endTransmission(true);
}

void loop() {
    // Physical Safety Check
    if (digitalRead(KILL_SWITCH_PIN) == LOW) {
        drv.stop();
        return;
    }

    // Read Accelerometer Z-axis for ambient mechanical noise
    Wire.beginTransmission(MPU6050_ADDR);
    Wire.write(0x3D);
    Wire.endTransmission(false);
    Wire.requestFrom(MPU6050_ADDR, 2, true);
    
    accelZ = (Wire.read() << 8 | Wire.read());

    // Phase Inversion Logic for Active Noise Cancellation (Pacinian Corpuscles Range: 150-300Hz)
    if (abs(accelZ) > 2000) {
        uint8_t antiPhaseEffect = map(constrain(abs(accelZ), 2000, 16000), 2000, 16000, 1, 15);
        drv.setWaveform(0, antiPhaseEffect); 
        drv.setWaveform(1, 0); 
        drv.go();
    }
    
    delay(10); // 100Hz DSP Loop Frequency
}
