# Cyberdeck

A handheld cyberdeck built with ESP32 + Samsung J7 Prime Android phone.
Functions as oscilloscope, signal generator, IMU monitor, and Linux handheld.

## Hardware
- ESP32 (hardware brain — controls all sensors and display)
- Samsung Galaxy J7 Prime (Linux brain via Termux — runs Python)
- 3.5" ILI9488 SPI TFT Display
- AD7606 ADC (oscilloscope input)
- AD9833 DDS Signal Generator
- ADS1115 ADC (general analog input)
- MPU6050 IMU (accelerometer + gyroscope)
- WS2812 8x8 RGB Matrix
- TP4056 USB-C charging + dual 18650 batteries
- KY-040 Rotary Encoder
- Mini Bluetooth Keyboard

## Phases
- [x] Phase 1: Git + Mac + Phone setup
- [ ] Phase 2: Power system
- [ ] Phase 3: ESP32 core + display + inputs
- [ ] Phase 4: Samsung J7 Prime brain setup
- [ ] Phase 5: Oscilloscope mode
- [ ] Phase 6: Signal generator mode
- [ ] Phase 7: Cyberdeck extras
- [ ] Phase 8: Final assembly
