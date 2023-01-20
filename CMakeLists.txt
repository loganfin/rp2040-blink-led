cmake_minimum_required(VERSION 3.13)

include(lib/pico-sdk/pico_sdk_init.cmake)

project(blink LANGUAGES C CXX ASM)

pico_sdk_init()

add_executable(blink src/main.c)
