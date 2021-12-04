set(handheld_game_SKETCH
  ${CMAKE_CURRENT_SOURCE_DIR}/HandheldGameSketch.ino
  PARENT_SCOPE
  )

set(handheld_game_SRCS
  ${CMAKE_CURRENT_SOURCE_DIR}/ArduinoInput.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/ArduinoScreen.cpp

  ${CMAKE_CURRENT_SOURCE_DIR}/GuiInput.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/GuiScreen.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/GuiMain.cpp

  ${CMAKE_CURRENT_SOURCE_DIR}/Brick.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Snek.cpp
  PARENT_SCOPE
  )

if(UNIX)
  add_executable(handleheld_game
    HandheldGameSketch.ino

    ArduinoInput.cpp
    ArduinoScreen.cpp

    GuiInput.cpp
    GuiScreen.cpp
    GuiMain.cpp

    Brick.cpp
    Snek.cpp
    )
endif()
