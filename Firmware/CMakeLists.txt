cmake_minimum_required(VERSION 3.13)
# Required by CMake: must be the first command
# Set PICO_SDK_PATH to local pico-sdk if not already set
if(NOT DEFINED PICO_SDK_PATH)
    set(PICO_SDK_PATH "${CMAKE_CURRENT_LIST_DIR}/pico-sdk")
endif()

include(${PICO_SDK_PATH}/pico_sdk_init.cmake)

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
