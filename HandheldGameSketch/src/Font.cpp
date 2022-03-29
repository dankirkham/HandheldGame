#include "Constants.h"
#include "Font.h"
#include "ProgMem.h"

void draw_text(
  Screen* screen,
  char* text,
  short start_x,
  short y
  ) {
  int x = start_x;

  for (int i = strlen(text); i >= 0; i--)
  {
    draw_letter(screen, text[i], x + (6 * i), y);
  }
}

void draw_letter(
  Screen* screen,
  char letter,
  short x,
  short y
  ) {
  bool buffer[FONT_WIDTH * FONT_HEIGHT];

  switch(letter) {
    case 'A':
      memcpy_P(buffer, letters::A, FONT_WIDTH * FONT_HEIGHT);
      break;
    case 'B':
      memcpy_P(buffer, letters::B, FONT_WIDTH * FONT_HEIGHT);
      break;
    case 'C':
      memcpy_P(buffer, letters::C, FONT_WIDTH * FONT_HEIGHT);
      break;
    case 'D':
      memcpy_P(buffer, letters::D, FONT_WIDTH * FONT_HEIGHT);
      break;
    case 'E':
      memcpy_P(buffer, letters::E, FONT_WIDTH * FONT_HEIGHT);
      break;
    case 'F':
      memcpy_P(buffer, letters::F, FONT_WIDTH * FONT_HEIGHT);
      break;
    case 'G':
      memcpy_P(buffer, letters::G, FONT_WIDTH * FONT_HEIGHT);
      break;
    case 'H':
      memcpy_P(buffer, letters::H, FONT_WIDTH * FONT_HEIGHT);
      break;
    case 'I':
      memcpy_P(buffer, letters::I, FONT_WIDTH * FONT_HEIGHT);
      break;
    case 'J':
      memcpy_P(buffer, letters::J, FONT_WIDTH * FONT_HEIGHT);
      break;
    case 'K':
      memcpy_P(buffer, letters::K, FONT_WIDTH * FONT_HEIGHT);
      break;
    case 'L':
      memcpy_P(buffer, letters::L, FONT_WIDTH * FONT_HEIGHT);
      break;
    case 'M':
      memcpy_P(buffer, letters::M, FONT_WIDTH * FONT_HEIGHT);
      break;
    case 'N':
      memcpy_P(buffer, letters::N, FONT_WIDTH * FONT_HEIGHT);
      break;
    case 'O':
      memcpy_P(buffer, letters::O, FONT_WIDTH * FONT_HEIGHT);
      break;
    case 'P':
      memcpy_P(buffer, letters::P, FONT_WIDTH * FONT_HEIGHT);
      break;
    case 'Q':
      memcpy_P(buffer, letters::Q, FONT_WIDTH * FONT_HEIGHT);
      break;
    case 'R':
      memcpy_P(buffer, letters::R, FONT_WIDTH * FONT_HEIGHT);
      break;
    case 'S':
      memcpy_P(buffer, letters::S, FONT_WIDTH * FONT_HEIGHT);
      break;
    case 'T':
      memcpy_P(buffer, letters::T, FONT_WIDTH * FONT_HEIGHT);
      break;
    case 'U':
      memcpy_P(buffer, letters::U, FONT_WIDTH * FONT_HEIGHT);
      break;
    case 'V':
      memcpy_P(buffer, letters::V, FONT_WIDTH * FONT_HEIGHT);
      break;
    case 'W':
      memcpy_P(buffer, letters::W, FONT_WIDTH * FONT_HEIGHT);
      break;
    case 'X':
      memcpy_P(buffer, letters::X_letter, FONT_WIDTH * FONT_HEIGHT);
      break;
    case 'Y':
      memcpy_P(buffer, letters::Y, FONT_WIDTH * FONT_HEIGHT);
      break;
    case 'Z':
      memcpy_P(buffer, letters::Z, FONT_WIDTH * FONT_HEIGHT);
      break;
    default:
      memcpy_P(buffer, letters::FULL, FONT_WIDTH * FONT_HEIGHT);
      break;
  }

  for (int i = 0; i < FONT_WIDTH; i++)
  {
    if (x + i < 0) continue;
    if (x + i >= COLUMNS) break;

    for (int j = 0; j < FONT_HEIGHT; j++)
    {
      if (y + j < 0) continue;
      if (y + j >= ROWS) break;
      if (*(buffer + j * FONT_WIDTH + i))
      {
        screen->setPixel(x + i, y + j);
      }
    }
  }
}
