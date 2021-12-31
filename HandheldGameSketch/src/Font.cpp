#include "Constants.h"
#include "Font.h"

void draw_text(
  bool* buf,
  char* text,
  short start_x,
  short y
  ) {

  int x = start_x;
  int i = 0;

  while (text[i] != '\0')
  {
    draw_letter(buf, text[i], x + (6 * i), y);

    i++;
  }
}

void draw_letter(
  bool* buf,
  char letter,
  short x,
  short y
  ) {
  const bool* lbuf;

  switch(letter) {
    case 'A':
      lbuf = letters::A;
      break;
    case 'B':
      lbuf = letters::B;
      break;
    case 'C':
      lbuf = letters::C;
      break;
    case 'D':
      lbuf = letters::D;
      break;
    case 'E':
      lbuf = letters::E;
      break;
    case 'F':
      lbuf = letters::F;
      break;
    case 'G':
      lbuf = letters::G;
      break;
    case 'H':
      lbuf = letters::H;
      break;
    case 'I':
      lbuf = letters::I;
      break;
    case 'J':
      lbuf = letters::J;
      break;
    case 'K':
      lbuf = letters::K;
      break;
    case 'L':
      lbuf = letters::L;
      break;
    case 'M':
      lbuf = letters::M;
      break;
    case 'N':
      lbuf = letters::N;
      break;
    case 'O':
      lbuf = letters::O;
      break;
    case 'P':
      lbuf = letters::P;
      break;
    case 'Q':
      lbuf = letters::Q;
      break;
    case 'R':
      lbuf = letters::R;
      break;
    case 'S':
      lbuf = letters::S;
      break;
    case 'T':
      lbuf = letters::T;
      break;
    case 'U':
      lbuf = letters::U;
      break;
    case 'V':
      lbuf = letters::V;
      break;
    case 'W':
      lbuf = letters::W;
      break;
    case 'X':
      lbuf = letters::X_letter;
      break;
    case 'Y':
      lbuf = letters::Y;
      break;
    case 'Z':
      lbuf = letters::Z;
      break;
    default:
      lbuf = letters::FULL;
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
      if (*(lbuf + j * FONT_WIDTH + i))
      {
        *(buf + (y + j) * COLUMNS + (x + i)) = true;
      }
    }
  }
}
