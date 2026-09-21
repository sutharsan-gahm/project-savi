
# Project SAVI: Ultra-Low-Cost Tactile Neuromodulation & Neuro-Safety Architecture
<p align="center">
  <img src="Use%20AI%20Image%20Sep%2021,%202026,%2011_25_04%20(1).jpeg" alt="Project SAVI Prototype" width="550">
</p>

<p align="center">
  <em>An IP67-rated, low-cost neuro-haptic band built on ESP32, featuring magnetic pogo-pin charging and a translucent silicone shell for non-invasive dementia care.</em>
</p>

[![ORCID](https://img.shields.io/badge/ORCID-0009--0003--7103--446X-green)](https://orcid.org/0009-0003-7103-446X)
[![Part 1 DOI](https://img.shields.io/badge/DOI-10.6084%2Fm9.figshare.33716230-blue)](https://doi.org/10.6084/m9.figshare.33716230)
[![Part 2 DOI](https://img.shields.io/badge/DOI-10.6084%2Fm9.figshare.33732142-blue)](https://doi.org/10.6084/m9.figshare.33732142)
[![Part 3 DOI](https://img.shields.io/badge/DOI-10.6084%2Fm9.figshare.33789736-blue)](https://doi.org/10.6084/m9.figshare.33789736)
[![OSHWA Certification Pending](https://img.shields.io/badge/OSHWA-Certification%20Pending-blue)](https://certificate.oshwa.org/)
[![License: CERN-OHL-P v2](https://img.shields.io/badge/Hardware-CERN--OHL--P%20v2-orange.svg)](LICENSE-HARDWARE.txt)
[![License: MIT](https://img.shields.io/badge/Firmware-MIT-yellow.svg)](LICENSE-FIRMWARE.txt)
[![License: CC BY 4.0](https://img.shields.io/badge/Docs-CC%20BY%204.0-lightgrey.svg)](LICENSE-DOCS.txt)

Project SAVI is an open-source, peer-verifiable neuro-safety wearable system designed to democratize access to tactile neuromodulation and active vibration control. Built on a strict **$15 Target Bill of Materials (BOM)**, it targets the human somatosensory system—the primary, evolutionary surface for biological communication.

---

## 🔬 Core Engineering Specifications

* **Target BOM:** ≤ $15 USD (Designed for global accessibility in resource-constrained research environments)
* **Microcontroller:** ESP32 (Tensilica LX6, Dual-core, Wi-Fi/BLE integrated)
* **Kinematic Sensing:** MPU6050 (6-axis I2C MotionTracking accelerometer & gyroscope)
* **Haptic Actuation:** DRV2605L (ERM/LRA Haptic Driver with integrated waveform library)
* **Neuromodulation Frequency:** Active noise/vibration cancellation & sensory targeting across **150–300 Hz**

---

## 📜 Open-Source Licensing & Compliance

Project SAVI fully adheres to strict Open-Source Hardware (OSHW) guidelines:

1. **Hardware (Schematics, PCB, Gerber):** [CERN-OHL-P v2](LICENSE-HARDWARE.txt) (Permissive)
2. **Firmware (C++ / ESP-IDF Driver):** [MIT License](LICENSE-FIRMWARE.txt)
3. **Documentation & Research Data:** [Creative Commons Attribution 4.0 International (CC BY 4.0)](LICENSE-DOCS.txt)

> **Certification Status:** Official application for **OSHWA (Open Source Hardware Association) Certification** has been submitted and is currently pending UID assignment.

---

## 🛠 Repository Architecture

```text
├── hardware/             # KiCad PCB schematics, Gerber files, and Interactive BOM
├── firmware/             # ESP32 C++ drivers, Sensor Fusion & Haptic DSP algorithms
├── docs/                 # Safety guidelines, Bio-Acoustic theory, and Assembly Guides
├── LICENSE-HARDWARE.txt  # CERN-OHL-P v2
├── LICENSE-FIRMWARE.txt  # MIT License
└── LICENSE-DOCS.txt      # CC BY 4.0
 ```
## 🌍 Philosophical Basis & Biological Alignment
​Modern speech and symbolic language are relatively recent evolutionary adaptations. Human physiology inherently utilizes the skin—the body's largest sensory interface—for direct environmental and neural synchronization. Project SAVI leverages this evolutionary somatosensory pathway to deliver tactile neuromodulation directly to the nervous system, bypassing auditory or visual cognitive overload.
​##🤝 Funding & Global Collaboration
​Project SAVI is an independent, human-led open science initiative developed by Sutharsan Sakathevan in Sri Lanka.
​We are actively applying for open-science grants to fund physical prototype fabrication and laboratory validation:
​NLnet Foundation (Open Internet Stack / Commons Fund)
​Open Collective & GitHub Grants
​How to Contribute
​Star & Fork: Help us gain visibility within the Open Science Hardware (GOSH) network.
​Firmware Optimization: Review our C++ sensor fusion loops in /firmware.
​Peer Review: Inspect our PCB routing and BOM breakdown in /hardware.
​Author: Sutharsan Sakathevan | Open Hardware Developer & Independent Researcher
Contact / Profile: https://github.com/sutharsan-gahm
### SAVI 4.0: Closed-Loop Somatosensory Bio-Feedback Architecture for Dementia Care
* **Scope:** $15 Target BOM active wearable delivering acoustic-to-tactile neuro-haptic grounding to reduce non-verbal cognitive overload and agitation.
* **Core Tech:** Dual-Core ESP32 Edge-DSP, Real-time FFT (85–255 Hz to 150–300 Hz Pacinian band), MPU6050 agitation detection, DRV2605L + 10mm LRA somatosensory anchoring.
* **DOI:** [10.6084/m9.figshare.33940801](https://doi.org/10.6084/m9.figshare.33940801)
* **License:** CERN-OHL-P v2 (Hardware) | MIT (Firmware) | CC BY 4.0 (Documentation)
* **Author ORCID:** [0009-0003-7103-446X](https://orcid.org/0009-0003-7103-446X)
