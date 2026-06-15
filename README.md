# ⚡ OSCIGEN
> Handheld Oscilloscope + Signal Generator Cyberdeck built on ESP32

![Status](https://img.shields.io/badge/status-in%20progress-yellow)
![Platform](https://img.shields.io/badge/platform-ESP32-blue)
![Language](https://img.shields.io/badge/language-MicroPython-green)

## What is OSCIGEN?
A portable cyberdeck built inside a Cadbury celebration box that can:
- 📈 Read and display signals (Oscilloscope)
- 📡 Generate signals (Signal Generator)
- 🎮 Tilt interface using MPU6050 accelerometer

## Built by
Purnima — 4th year ENI, BITS Goa 🎓
# Cyberdeck

A handheld ESP32 + Raspberry Pi Zero 2W cyberdeck that doubles as an oscilloscope and signal generator.

## Hardware
- ESP32
- 3.5" ILI9488 SPI TFT Display
- AD7606 8-channel ADC (oscilloscope input)
- AD9833 DDS Signal Generator
- TP4056 USB-C charging + dual 18650 batteries
- Raspberry Pi Zero 2W (Linux companion)
- WS2812 8×8 RGB Matrix
- MPU6050 IMU
- KY-040 Rotary Encoder

## Phases
- [ ] Phase 1: Git & dev environment
- [ ] Phase 2: Power system
- [ ] Phase 3: ESP32 core UI
- [ ] Phase 4: Oscilloscope mode
- [ ] Phase 5: Signal generator mode
- [ ] Phase 6: Cyberdeck extras
- [ ] Phase 7: RPi Zero + final assembly