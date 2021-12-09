cmake_minimum_required(VERSION 3.12)

project(handheld_game)

if(UNIX)
  find_package(Qt5 COMPONENTS Widgets REQUIRED)
endif()

add_subdirectory(include)
include_directories(include)
add_subdirectory(src)

if(CMAKE_SYSTEM_NAME STREQUAL "Arduino")
  # This fixes inssues with finding the boards.txt file
  # https://github.com/queezythegreat/arduino-cmake/issues/146#issuecomment-447103253
  register_hardware_platform(${ARDUINO_SDK_PATH}/hardware/arduino/avr)

  generate_arduino_firmware(
    handheld_game
    BOARD uno
    )
endif()

