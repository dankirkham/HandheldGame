#include "Game.h"
#include "Brick.h"
#include "Pins.h"
#include "Screen.h"
#include "Random.h"

const int PADDLE_Y = ROWS - 1;

Brick::Brick(Screen* screen, Input* input) : Game() {
  this->screen = screen;
  this->input = input;
  this->init();
}

int Brick::getDelay() {
  return Brick::DELAY;
}

void Brick::init() {
  // Init the snek
  state.ball_pos_x = 8;
  state.ball_pos_y = PADDLE_Y - 1;
  state.ball_vel_x = 1;
  state.ball_vel_y = -1;
  state.paddle_x = 8;
  state.game_over = false;
  state.paused = false;
  state.ball_timer = Brick::BALL_DELAY;
  for (int i = 0; i < COLUMNS * Brick::BRICK_ROWS; i++) {
    state.bricks[i] = true;
  }
}

void Brick::tick() {
  // Back to MENU
  if (input->keyDown(button_e::start) && input->keyDown(button_e::select)) {
    this->gameToSwitchTo = games_e::MENU;
  }

  // Handle reset
  if (input->keyDown(button_e::select)) {
    this->init();
  }

  if (input->keyDown(button_e::start)) {
    state.paused = !state.paused;
  }

  if (!state.paused && !state.game_over) {
    // Move Paddle
    if (input->keyDown(button_e::left)) {
      if (state.paddle_x > 1) {
        state.paddle_x -= 1;
      }
    }
    if (input->keyDown(button_e::right)) {
      if (state.paddle_x < COLUMNS - 2) {
        state.paddle_x += 1;
      }
    }

    state.ball_timer -= 1;
    if (state.ball_timer <= 0) {
      state.ball_timer = Brick::BALL_DELAY;

      // Find next ball position
      int next_ball_x = state.ball_pos_x + state.ball_vel_x;
      int next_ball_y = state.ball_pos_y + state.ball_vel_y;

      bool collision;
      do {
        collision = false;

        // Check paddle
        if (next_ball_y == PADDLE_Y) {
          if (state.ball_pos_x == state.paddle_x) {
            // Center of paddle
            // Bounce up, keep x vel
            state.ball_vel_y = -1;
            collision = true;
          } else if (state.ball_pos_x == state.paddle_x - 1) {
            // Left edge of paddle
            // Bounce up, move left
            state.ball_vel_x = -1;
            state.ball_vel_y = -1;

            // Ball has a 50% to glance and move left twice.
            if (random(0, 1) == 1) {
              state.ball_pos_x -= 1;
            }

            collision = true;
          } else if (state.ball_pos_x == state.paddle_x + 1) {
            // Right edge of paddle
            // Bounce up, move right
            state.ball_vel_x = 1;
            state.ball_vel_y = -1;

            // Ball has a 50% to glance and move right twice.
            if (random(0, 1) == 1) {
              state.ball_pos_x += 1;
            }

            collision = true;
          //} else if (next_ball_x == state.paddle_x - 1) {
          //  // Left edge of paddle
          //  // Bounce up, move left
          //  state.ball_vel_x = -1;
          //  state.ball_vel_y = -1;

          //  // Ball has a 50% to glance and move left twice.
          //  if (random(0, 1) == 1) {
          //    state.ball_pos_x -= 1;
          //  }

          //  collision = true;
          //} else if (next_ball_x == state.paddle_x + 1) {
          //  // Right edge of paddle
          //  // Bounce up, move right
          //  state.ball_vel_x = 1;
          //  state.ball_vel_y = -1;

          //  // Ball has a 50% to glance and move right twice.
          //  if (random(0, 1) == 1) {
          //    state.ball_pos_x += 1;
          //  }

          //  collision = true;
          }

            // Move ball again
          next_ball_x = state.ball_pos_x + state.ball_vel_x;
          next_ball_y = state.ball_pos_y + state.ball_vel_y;
        }

        // Check for brick collision
        if (
          next_ball_y < Brick::BRICK_ROWS &&
          next_ball_y >= 0 &&
          next_ball_x >= 0 &&
          next_ball_x < COLUMNS
        ) {
          bool hit = false;
          bool vertical_hit = false;
          bool horizontal_hit = false;

          if (state.bricks[next_ball_y * COLUMNS + next_ball_x]) {
            state.bricks[next_ball_y * COLUMNS + next_ball_x] = false;
            hit = true;
          }

          // Adjacent blocks
          // Up
          if (
            state.ball_pos_y > 0 &&
            state.bricks[(state.ball_pos_y - 1) * COLUMNS + state.ball_pos_x]
          ) {
            state.bricks[(state.ball_pos_y - 1) * COLUMNS + state.ball_pos_x] = false;
            vertical_hit = true;
          }
          // Down
          if (
            state.ball_pos_y < Brick::BRICK_ROWS - 1 &&
            state.bricks[(state.ball_pos_y + 1) * COLUMNS + state.ball_pos_x]
          ) {
            state.bricks[(state.ball_pos_y + 1) * COLUMNS + state.ball_pos_x] = false;
            vertical_hit = true;
          }
          // Left
          if (
            state.ball_pos_x > 0 &&
            state.bricks[state.ball_pos_y * COLUMNS + state.ball_pos_x - 1]
          ) {
            state.bricks[state.ball_pos_y * COLUMNS + state.ball_pos_x - 1] = false;
            horizontal_hit = true;
          }
          // Right
          if (
            state.ball_pos_x < COLUMNS - 1 &&
            state.bricks[state.ball_pos_y * COLUMNS + state.ball_pos_x + 1]
          ) {
            state.bricks[state.ball_pos_y * COLUMNS + state.ball_pos_x + 1] = false;
            horizontal_hit = true;
          }

          if (hit || vertical_hit || horizontal_hit) {
            // Bounce
            state.ball_vel_y = state.ball_vel_y == 1 ? -1 : 1;
            if (vertical_hit && horizontal_hit) {
              state.ball_vel_x = state.ball_vel_x == 1 ? -1 : 1;
            }
            collision = true;
          }
        }

        // Move ball again, in case it bounced
        next_ball_x = state.ball_pos_x + state.ball_vel_x;
        next_ball_y = state.ball_pos_y + state.ball_vel_y;

        // Check for wall collision
        // Bounce x
        if (next_ball_x < 0) {
          state.ball_vel_x = 1;
          collision = true;
        } else if (next_ball_x > (COLUMNS - 1)) {
          state.ball_vel_x = -1;
          collision = true;
        }

        // Bounce y or game over
        if (next_ball_y < 0) {
          state.ball_vel_y = 1;
          collision = true;
        } else if (next_ball_y > (ROWS - 1)) {
          state.game_over = true;
          break;
        }

        // Move ball again, in case it bounced
        next_ball_x = state.ball_pos_x + state.ball_vel_x;
        next_ball_y = state.ball_pos_y + state.ball_vel_y;

      } while (collision);

      // Move ball
      if (next_ball_x >= 0 && next_ball_x < COLUMNS) {
        state.ball_pos_x = next_ball_x;
      }
      if (next_ball_y >= 0 && next_ball_y < ROWS) {
        state.ball_pos_y = next_ball_y;
      }
    }
  }

  screen->erase();

  // Draw ball
  screen->setPixel(state.ball_pos_x, state.ball_pos_y);

  // Draw paddle
  screen->setPixel(state.paddle_x - 1, PADDLE_Y);
  screen->setPixel(state.paddle_x, PADDLE_Y);
  screen->setPixel(state.paddle_x + 1, PADDLE_Y);

  // Draw bricks
  for (int x = 0; x < COLUMNS; x++) {
    for (int y = 0; y < Brick::BRICK_ROWS; y++) {
      int i = y * COLUMNS + x;
      if (state.bricks[i]) {
        screen->setPixel(x, y);
      }
    }
  }
}
