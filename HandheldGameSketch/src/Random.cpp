#include <Random.h>

#ifndef ARDUINO
#include <stdlib.h>

int random(const int min, const int max)
{
  return rand() % max + min;
}

#endif
