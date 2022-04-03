set(handheld_game_SKETCH
  ${CMAKE_CURRENT_SOURCE_DIR}/HandheldGameSketch.ino
  PARENT_SCOPE
  )

set(handheld_game_SRCS
  ${CMAKE_CURRENT_SOURCE_DIR}/Executor.cpp

  ${CMAKE_CURRENT_SOURCE_DIR}/ArduinoInput.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/ArduinoScreen.cpp

  ${CMAKE_CURRENT_SOURCE_DIR}/GuiInput.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/GuiScreen.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/GuiMain.cpp

  ${CMAKE_CURRENT_SOURCE_DIR}/Pins.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Font.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Input.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Screen.cpp

  ${CMAKE_CURRENT_SOURCE_DIR}/Random.cpp

  ${CMAKE_CURRENT_SOURCE_DIR}/Game.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Menu.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Brick.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Snek.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Birb.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Tetris.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Pong.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Quest.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Counter.cpp

  PARENT_SCOPE
  )

if(UNIX)
  add_executable(handheld_game
    HandheldGameSketch.ino

    Executor.cpp

    ArduinoInput.cpp
    ArduinoScreen.cpp

    GuiInput.cpp
    GuiScreen.cpp
    GuiMain.cpp
    MainWindow.cpp

    Pins.cpp
    Font.cpp
    Input.cpp
    Screen.cpp

    Random.cpp

    Game.cpp
    Menu.cpp
    Brick.cpp
    Snek.cpp
    Birb.cpp
    Tetris.cpp
    Pong.cpp
    Quest.cpp
    Counter.cpp

    # For moc to work...
    ../include/MainWindow.h
    )

  target_link_libraries(handheld_game Qt5::Widgets)
endif()
