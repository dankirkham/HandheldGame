#ifndef ProgMem_h
#define ProgMem_h

#include <string.h>

#ifdef ARDUINO
#include <avr/pgmspace.h>
#else
#define PROGMEM
#define PGM_P const char *
#define pgm_read_word *
#define memcpy_P memcpy
#define strcpy_P strcpy
#endif

#endif // ProgMem_h
