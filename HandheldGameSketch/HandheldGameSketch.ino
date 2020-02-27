// Constants
#define PIN_SHIFT_DATA 0 // PD0
#define PIN_SHIFT_CLOCK 1 // PD1
#define PIN_SHIFT_LATCH 2 // PD2
#define PIN_DECADE_RESET 3 // PD3
#define PIN_DECADE_CLOCK 4 // PD4
#define PIN_BUTTON_START 9 // PB1
#define PIN_BUTTON_SELECT 10 // PB2
#define PIN_BUTTON_A A0 // PC0
#define PIN_BUTTON_B A1 // PC1
#define PIN_BUTTON_UP A2 // PC2
#define PIN_BUTTON_LEFT A3 // PC3
#define PIN_BUTTON_DOWN A4 // PC4
#define PIN_BUTTON_RIGHT A5 // PC5

#define ROWS 10
#define COLUMNS 16

#define SNAKE_MAX_LENGTH 160
#define SNAKE_DELAY 100

// Data Types
enum Direction {
  UP,
  RIGHT,
  DOWN,
  LEFT
};

struct SnakeGame {
  short len;
  short food_x;
  short food_y;
  short body_x[SNAKE_MAX_LENGTH];
  short body_y[SNAKE_MAX_LENGTH];
  Direction dir;
  bool game_over;
  bool paused;
};

// Variables
bool buffer_1[ROWS * COLUMNS] = { false };
bool buffer_2[ROWS * COLUMNS] = { false };
bool *screen = (bool*) buffer_1;
bool *buf = (bool*) buffer_2;
SnakeGame snek;
int counter;
bool key_up;
bool key_right;
bool key_down;
bool key_left;
bool key_select;
bool key_start;

void draw() {
  digitalWrite(PIN_DECADE_RESET, HIGH);
  digitalWrite(PIN_SHIFT_DATA, LOW);
  digitalWrite(PIN_SHIFT_CLOCK, LOW);
  digitalWrite(PIN_SHIFT_LATCH, LOW);
  digitalWrite(PIN_DECADE_RESET, LOW);
  digitalWrite(PIN_DECADE_CLOCK, LOW);

  for (int i = 0; i < ROWS; i++) {
    for (int j = COLUMNS - 1; j >= 0; j--) {
      digitalWrite(PIN_SHIFT_DATA, *(screen + i * COLUMNS + j) ? HIGH : LOW);
//      digitalWrite(PIN_SHIFT_DATA, ((i + j) % 2 == 0) ? HIGH : LOW);
      digitalWrite(PIN_SHIFT_CLOCK, HIGH);
      digitalWrite(PIN_SHIFT_CLOCK, LOW);
    }

    if (i != 0) {
      PORTD |= (1 << PD2) | (1 << PD4);
    } else {
      digitalWrite(PIN_SHIFT_LATCH, HIGH);
    }
    
    
    digitalWrite(PIN_SHIFT_LATCH, LOW);
    digitalWrite(PIN_DECADE_CLOCK, LOW);
  }

  // Last row gets same display time as the other rows
  for (int j = COLUMNS - 1; j >= 0; j--) {
      digitalWrite(PIN_SHIFT_DATA, LOW);
      digitalWrite(PIN_SHIFT_CLOCK, HIGH);
      digitalWrite(PIN_SHIFT_CLOCK, LOW);
  }
  
  PORTD |= (1 << PD2) | (1 << PD4);
  digitalWrite(PIN_SHIFT_LATCH, LOW);
  digitalWrite(PIN_DECADE_CLOCK, LOW);
}

void erase() {
  for (int i = 0; i < ROWS * COLUMNS; i++) {
      *(buf + i) = false;
  }
}

bool keyPressed(int key) {
  bool val = false;
  
  switch (key) {
    case PIN_BUTTON_UP:
      val = !digitalRead(PIN_BUTTON_UP);
      key_up = false;
      break;
    case PIN_BUTTON_RIGHT:
      val = !digitalRead(PIN_BUTTON_RIGHT);
      key_right = false;
      break;
    case PIN_BUTTON_DOWN:
      val = !digitalRead(PIN_BUTTON_DOWN);
      key_down = false;
      break;
    case PIN_BUTTON_LEFT:
      val = !digitalRead(PIN_BUTTON_LEFT);
      key_left = false;
      break;
    case PIN_BUTTON_SELECT:
      val = !digitalRead(PIN_BUTTON_SELECT);
      key_select = false;
      break;
    case PIN_BUTTON_START:
      val = key_start;
      key_start = false;
      break;
  }

  return val;
}

void setup() {
  pinMode(PIN_SHIFT_DATA, OUTPUT);
  pinMode(PIN_SHIFT_CLOCK, OUTPUT);
  pinMode(PIN_SHIFT_LATCH, OUTPUT);

  pinMode(PIN_DECADE_RESET, OUTPUT);
  pinMode(PIN_DECADE_CLOCK, OUTPUT);

//  // Init Screen
//  for (int i = 0; i < ROWS; i++) {
//    for (int j = 0; j < COLUMNS; j++) {
//      screen[i][j] = false;
//    }
//  }

//  // Test Screen
//  for (int i = 0; i < ROWS; i++) {
//    for (int j = 0; j < COLUMNS; j++) {
//      screen[i][j] = (i + j) % 2 == 0;
//    }
//  }

  // Init the snek
  snek.dir = RIGHT;
  snek.len = 3;
  snek.body_x[0] = 5;
  snek.body_y[0] = 5;
  snek.body_x[1] = 4;
  snek.body_y[1] = 5;
  snek.body_x[2] = 3;
  snek.body_y[2] = 5;
  snek.food_x = 3;
  snek.food_y = 3;
  snek.game_over = false;
  snek.paused = false;

  // Timer config
  counter = SNAKE_DELAY;
  TCCR0A = (1<<WGM01); // CTC mode 
  OCR0A = 0xF9; // 1 ms
  TIMSK0 |= (1<<OCIE0A); // Interrupt enable
  TCCR0B |= (1<<CS01) | (1<<CS00); // 1/64 prescale
//  TCCR0B |= (1<<CS02); // 1/256 prescale
  sei(); // Global interrupt enable
}

void tick() {
  if (keyPressed(PIN_BUTTON_SELECT)) {
    // Init the snek
    snek.dir = RIGHT;
    snek.len = 3;
    snek.body_x[0] = 5;
    snek.body_y[0] = 5;
    snek.body_x[1] = 4;
    snek.body_y[1] = 5;
    snek.body_x[2] = 3;
    snek.body_y[2] = 5;
    snek.food_x = 3;
    snek.food_y = 3;
    snek.game_over = false;
    snek.paused = false;
  } else if (keyPressed(PIN_BUTTON_START)) {
    snek.paused = !snek.paused;
  } else if (!snek.game_over && !snek.paused) {
    // Change dir
    if (keyPressed(PIN_BUTTON_UP) && snek.dir != DOWN) {
      snek.dir = UP;
    } else if (keyPressed(PIN_BUTTON_RIGHT) && snek.dir != LEFT) {
      snek.dir = RIGHT;
    } else if (keyPressed(PIN_BUTTON_DOWN) && snek.dir != UP) {
      snek.dir = DOWN;
    } else if (keyPressed(PIN_BUTTON_LEFT) && snek.dir != RIGHT) {
      snek.dir = LEFT;
    }
    
    // Move the snek body
    for (int i = snek.len - 1; i > 0; i--) {
      snek.body_x[i] = snek.body_x[i - 1];
      snek.body_y[i] = snek.body_y[i - 1];
    }

    // Find new snek hed pos
    short new_head_x = snek.body_x[0];
    short new_head_y = snek.body_y[0];
    switch (snek.dir) {
      case UP:
        new_head_y = snek.body_y[0] - 1;
        break;
      case RIGHT:
        new_head_x = snek.body_x[0] + 1;
        break;
      case DOWN:
        new_head_y = snek.body_y[0] + 1;
        break;
      case LEFT:
        new_head_x = snek.body_x[0] - 1;
        break;
    }

    // Check Mr. Snek for game over
    if (
      new_head_x < 0 ||
      new_head_x > COLUMNS - 1 ||
      new_head_y < 0 ||
      new_head_y > ROWS - 1
    ) {
      snek.game_over = true;
    }
    else {
      snek.body_x[0] = new_head_x;
      snek.body_y[0] = new_head_y;
    }

    // Chck Mr. Snek for foodz
    if (new_head_x == snek.food_x && new_head_y == snek.food_y) {
      // Make snek long
      snek.len += 1;

      // Snek gro backwards
      snek.body_x[snek.len - 1] = snek.body_x[snek.len - 2];
      snek.body_y[snek.len - 1] = snek.body_y[snek.len - 2];

      // New foods
      snek.food_x = random(0, COLUMNS - 1);
      snek.food_y = random(0, ROWS - 1);
      // TODO: Make food not spawn inside of Mr. Snek
    }
  }

  // Paint mr snek
  erase();
  for (int i = 0; i < snek.len; i++) {
    *(buf + snek.body_y[i] * COLUMNS + snek.body_x[i]) = true;
  }

  // Draw food
  *(buf + snek.food_y * COLUMNS + snek.food_x) = true;

  // Swap screen and buffer
  bool *temp = screen;
  screen = buf;
  buf = temp;
}

void loop() {
  if (!digitalRead(PIN_BUTTON_UP)) {
    key_up = true;
  } else if (!digitalRead(PIN_BUTTON_RIGHT)) {
    key_right = true;
  } else if (!digitalRead(PIN_BUTTON_DOWN)) {
    key_down = true;
  } else if (!digitalRead(PIN_BUTTON_LEFT)) {
    key_left = true;
  } else if (!digitalRead(PIN_BUTTON_SELECT)) {
    key_select = true;
  } else if (!digitalRead(PIN_BUTTON_START)) {
    key_start = true;
  }
}

ISR(TIMER0_COMPA_vect) {
  counter--;
  if (counter == 0) {
    counter = SNAKE_DELAY;
    tick();
  }
  
  draw();
}

