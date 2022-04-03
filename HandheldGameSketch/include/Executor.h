#ifndef __EXECUTOR_H__
#define __EXECUTOR_H__

#include "Input.h"
#include "Screen.h"

#include "Game.h"

#include "Snek.h"
#include "Menu.h"
#include "Birb.h"
#include "Tetris.h"
#include "Counter.h"
#include "Pong.h"
#include "Quest.h"
#include "Brick.h"

#ifdef ARDUINO
void *operator new(size_t, void*);
void operator delete(void*, unsigned int);

static char input_buffer[sizeof(Input)];
static char screen_buffer[sizeof(Screen)];
const auto game_buffer_size = sizeof(Quest) * 2; // Snek is our biggest game
static char game_buffer[game_buffer_size];

#define INPUT_BUFFER (input_buffer)
#define SCREEN_BUFFER (screen_buffer)
#define GAME_BUFFER (game_buffer)
#else
#define INPUT_BUFFER
#define SCREEN_BUFFER
#define GAME_BUFFER
#endif

// This helps us determine RAM utilization at compile time
#if 0
char (*__kaboom0)[sizeof( Input )] = 1;
char (*__kaboom1)[sizeof( Screen )] = 1;
char (*__kaboom2)[sizeof( Snek )] = 1;
char (*__kaboom3)[sizeof( Brick )] = 1;
char (*__kaboom4)[sizeof( Birb )] = 1;
char (*__kaboom5)[sizeof( Tetris )] = 1;
char (*__kaboom6)[sizeof( Menu )] = 1;
#endif

class Executor {
public:
  static Input* input;
  static Screen* screen;

  static void tick();

private:
  static Game* game;
  static int counter;
};

#endif // __EXECUTOR_H__
