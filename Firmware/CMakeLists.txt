cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(OpenRGB_Pico_Controller C CXX ASM)

pico_sdk_init()


add_executable(openrgb_pico_controller
    main.c
    openrgb_protocol.c
    openrgb_protocol.h
    usb_descriptors.c
)

target_link_libraries(openrgb_pico_controller pico_stdlib tinyusb_device tinyusb_board hardware_pwm)

pico_add_extra_outputs(openrgb_pico_controller)
