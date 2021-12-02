# Handheld Game Firmware

## Building on MacOS
```bash
brew tap osx-cross/avr
brew install avr-gcc
mkdir build-avr
cd build-avr
cmake -DCMAKE_TOOLCHAIN_FILE=../cmake/ArduinoToolchain.cmake -DARDUINO_SDK_PATH=/Applications/Arduino.app/Contents/Java/ ..
```
