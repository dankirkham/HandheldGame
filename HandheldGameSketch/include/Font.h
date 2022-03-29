#ifndef __FONT_HPP__
#define __FONT_HPP__

#include "ProgMem.h"
#include "Constants.h"
#include "Screen.h"

#define FONT_WIDTH 5
#define FONT_HEIGHT 7

#define X true
#define _ false

namespace letters {

const bool FULL[FONT_WIDTH * FONT_HEIGHT] PROGMEM = {
  X,X,X,X,X,
  X,X,X,X,X,
  X,X,X,X,X,
  X,X,X,X,X,
  X,X,X,X,X,
  X,X,X,X,X,
  X,X,X,X,X
};

const bool EMPTY[FONT_WIDTH * FONT_HEIGHT] PROGMEM = {
  _,_,_,_,_,
  _,_,_,_,_,
  _,_,_,_,_,
  _,_,_,_,_,
  _,_,_,_,_,
  _,_,_,_,_,
  _,_,_,_,_
};

const bool A[FONT_WIDTH * FONT_HEIGHT] PROGMEM = {
  _,_,X,_,_,
  _,X,_,X,_,
  X,_,_,_,X,
  X,X,X,X,X,
  X,_,_,_,X,
  X,_,_,_,X,
  X,_,_,_,X
};

const bool B[FONT_WIDTH * FONT_HEIGHT] PROGMEM = {
  X,X,X,X,_,
  X,_,_,_,X,
  X,_,_,_,X,
  X,X,X,X,_,
  X,_,_,_,X,
  X,_,_,_,X,
  X,X,X,X,_
};

const bool C[FONT_WIDTH * FONT_HEIGHT] PROGMEM = {
  _,X,X,X,_,
  X,_,_,_,X,
  X,_,_,_,_,
  X,_,_,_,_,
  X,_,_,_,_,
  X,_,_,_,X,
  _,X,X,X,_
};

const bool D[FONT_WIDTH * FONT_HEIGHT] PROGMEM = {
  X,X,X,X,_,
  X,_,_,_,X,
  X,_,_,_,X,
  X,_,_,_,X,
  X,_,_,_,X,
  X,_,_,_,X,
  X,X,X,X,_
};

const bool E[FONT_WIDTH * FONT_HEIGHT] PROGMEM = {
  X,X,X,X,X,
  X,_,_,_,_,
  X,_,_,_,_,
  X,X,X,X,_,
  X,_,_,_,_,
  X,_,_,_,_,
  X,X,X,X,X
};

const bool F[FONT_WIDTH * FONT_HEIGHT] PROGMEM = {
  X,X,X,X,X,
  X,_,_,_,_,
  X,_,_,_,_,
  X,X,X,X,_,
  X,_,_,_,_,
  X,_,_,_,_,
  X,_,_,_,_
};

const bool G[FONT_WIDTH * FONT_HEIGHT] PROGMEM = {
  _,X,X,X,_,
  X,_,_,_,X,
  X,_,_,_,_,
  X,_,_,_,_,
  X,_,X,X,X,
  X,_,_,_,X,
  _,X,X,X,_
};

const bool H[FONT_WIDTH * FONT_HEIGHT] PROGMEM = {
  X,_,_,_,X,
  X,_,_,_,X,
  X,_,_,_,X,
  X,X,X,X,X,
  X,_,_,_,X,
  X,_,_,_,X,
  X,_,_,_,X
};

const bool I[FONT_WIDTH * FONT_HEIGHT] PROGMEM = {
  _,X,X,X,_,
  _,_,X,_,_,
  _,_,X,_,_,
  _,_,X,_,_,
  _,_,X,_,_,
  _,_,X,_,_,
  _,X,X,X,_
};

const bool J[FONT_WIDTH * FONT_HEIGHT] PROGMEM = {
  _,_,_,_,X,
  _,_,_,_,X,
  _,_,_,_,X,
  _,_,_,_,X,
  _,_,_,_,X,
  X,_,_,_,X,
  _,X,X,X,_
};

const bool K[FONT_WIDTH * FONT_HEIGHT] PROGMEM = {
  X,_,_,_,X,
  X,_,_,X,_,
  X,_,X,_,_,
  X,X,_,_,_,
  X,_,X,_,_,
  X,_,_,X,_,
  X,_,_,_,X
};

const bool L[FONT_WIDTH * FONT_HEIGHT] PROGMEM = {
  X,_,_,_,_,
  X,_,_,_,_,
  X,_,_,_,_,
  X,_,_,_,_,
  X,_,_,_,_,
  X,_,_,_,_,
  X,X,X,X,X
};

const bool M[FONT_WIDTH * FONT_HEIGHT] PROGMEM = {
  X,_,_,_,X,
  X,X,_,X,X,
  X,_,X,_,X,
  X,_,_,_,X,
  X,_,_,_,X,
  X,_,_,_,X,
  X,_,_,_,X
};

const bool N[FONT_WIDTH * FONT_HEIGHT] PROGMEM = {
  X,_,_,_,X,
  X,_,_,_,X,
  X,X,_,_,X,
  X,_,X,_,X,
  X,_,_,X,X,
  X,_,_,_,X,
  X,_,_,_,X
};

const bool O[FONT_WIDTH * FONT_HEIGHT] PROGMEM = {
  _,X,X,X,_,
  X,_,_,_,X,
  X,_,_,_,X,
  X,_,_,_,X,
  X,_,_,_,X,
  X,_,_,_,X,
  _,X,X,X,_
};

const bool P[FONT_WIDTH * FONT_HEIGHT] PROGMEM = {
  X,X,X,X,_,
  X,_,_,_,X,
  X,_,_,_,X,
  X,X,X,X,_,
  X,_,_,_,_,
  X,_,_,_,_,
  X,_,_,_,_
};

const bool Q[FONT_WIDTH * FONT_HEIGHT] PROGMEM = {
  _,X,X,X,_,
  X,_,_,_,X,
  X,_,_,_,X,
  X,_,_,_,X,
  X,_,_,_,X,
  X,_,X,_,X,
  _,X,X,X,_
};

const bool R[FONT_WIDTH * FONT_HEIGHT] PROGMEM = {
  X,X,X,X,_,
  X,_,_,_,X,
  X,_,_,_,X,
  X,X,X,X,_,
  X,_,_,_,X,
  X,_,_,_,X,
  X,_,_,_,X
};

const bool S[FONT_WIDTH * FONT_HEIGHT] PROGMEM = {
  _,X,X,X,_,
  X,_,_,_,X,
  X,_,_,_,_,
  _,X,X,X,_,
  _,_,_,_,X,
  X,_,_,_,X,
  _,X,X,X,_
};

const bool T[FONT_WIDTH * FONT_HEIGHT] PROGMEM = {
  X,X,X,X,X,
  _,_,X,_,_,
  _,_,X,_,_,
  _,_,X,_,_,
  _,_,X,_,_,
  _,_,X,_,_,
  _,_,X,_,_
};

const bool U[FONT_WIDTH * FONT_HEIGHT] PROGMEM = {
  X,_,_,_,X,
  X,_,_,_,X,
  X,_,_,_,X,
  X,_,_,_,X,
  X,_,_,_,X,
  X,_,_,_,X,
  _,X,X,X,_
};

const bool V[FONT_WIDTH * FONT_HEIGHT] PROGMEM = {
  X,_,_,_,X,
  X,_,_,_,X,
  X,_,_,_,X,
  X,_,_,_,X,
  X,_,_,_,X,
  _,X,_,X,_,
  _,_,X,_,_
};

const bool W[FONT_WIDTH * FONT_HEIGHT] PROGMEM = {
  X,_,_,_,X,
  X,_,_,_,X,
  X,_,_,_,X,
  X,_,_,_,X,
  X,_,X,_,X,
  X,X,_,X,X,
  X,_,_,_,X
};

const bool X_letter[FONT_WIDTH * FONT_HEIGHT] PROGMEM = {
  X,_,_,_,X,
  X,_,_,_,X,
  _,X,_,X,_,
  _,_,X,_,_,
  _,X,_,X,_,
  X,_,_,_,X,
  X,_,_,_,X
};

const bool Y[FONT_WIDTH * FONT_HEIGHT] PROGMEM = {
  X,_,_,_,X,
  X,_,_,_,X,
  X,_,_,_,X,
  _,X,_,X,_,
  _,_,X,_,_,
  _,_,X,_,_,
  _,_,X,_,_
};

const bool Z[FONT_WIDTH * FONT_HEIGHT] PROGMEM = {
  X,X,X,X,X,
  _,_,_,_,X,
  _,_,_,X,_,
  _,_,X,_,_,
  _,X,_,_,_,
  X,_,_,_,_,
  X,X,X,X,X
};

} // letters

void draw_text(Screen*, char*, short, short);
void draw_letter(Screen*, char, short, short);

#endif // __FONT_HPP__
