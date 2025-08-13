cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(mclk_project C CXX ASM)
pico_sdk_init()

add_executable(mclk main.c)
target_link_libraries(mclk pico_stdlib hardware_pwm)
pico_add_extra_outputs(mclk)
