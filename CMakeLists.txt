cmake_minimum_required(VERSION 3.13)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

# If PICO_SDK_PATH is defined on the user's system, use that. Else, use the git submodule included in this repo
if(DEFINED ENV{PICO_SDK_PATH})
    message(STATUS "Copying $ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake to ${CMAKE_SOURCE_DIR}")
    file(COPY $ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake
        DESTINATION ${CMAKE_SOURCE_DIR})
    include(pico_sdk_import.cmake)
else()
    if(EXISTS ${CMAKE_SOURCE_DIR}/lib/pico-sdk/pico_sdk_init.cmake)
        include(lib/pico-sdk/pico_sdk_init.cmake)
    else()
        message(FATAL_ERROR "lib/pico-sdk/pico_sdk_init.cmake was not found. Make sure to run
        git submodule update --init
        git -C lib/pico-sdk/ submodule update --init")
    endif()
endif()

project(blink LANGUAGES C CXX ASM)

set(PICO_BOARD adafruit_feather_rp2040)
pico_sdk_init()

add_executable(blink src/main.c)
target_link_libraries(blink pico_stdlib)

pico_add_extra_outputs(blink)

