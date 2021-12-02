set(handheld_game_SKETCH
  ${CMAKE_CURRENT_SOURCE_DIR}/HandheldGameSketch.ino
  PARENT_SCOPE
  )

set(handheld_game_SRCS
  ${CMAKE_CURRENT_SOURCE_DIR}/Brick.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Input.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Screen.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Snek.cpp
  PARENT_SCOPE
  )
