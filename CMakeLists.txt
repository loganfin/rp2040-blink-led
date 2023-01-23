cmake_minimum_required(VERSION 3.13)
include(lib/pico-sdk/pico_sdk_init.cmake)
project(blink LANGUAGES C CXX ASM)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(PICO_BOARD adafruit_feather_rp2040)
pico_sdk_init()

add_executable(blink src/main.c)
target_link_libraries(blink pico_stdlib)

pico_add_extra_outputs(blink)
