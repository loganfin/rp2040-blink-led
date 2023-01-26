# rp2040-blink-led

A hello world program for the RP2040-based Adafruit Pico Feather. This program will blink the d13 LED in an SOS pattern.

To build:

```
    git clone https://github.com/loganfin/rp2040-blink-led.git
    cd rp2040-blink-led
    git submodule update --init
    git -C lib/pico-sdk/ submodule update --init
    cmake -B build
    cmake --build build
```

blink.uf2 will be located in the build folder.
