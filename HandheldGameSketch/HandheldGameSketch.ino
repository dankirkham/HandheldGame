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

// Variables
bool screen[ROWS][COLUMNS];

int text[10][21] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0 },
  { 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1 },
  { 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1 },
  { 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1 },
  { 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

void draw() {
  digitalWrite(PIN_DECADE_RESET, HIGH);
  digitalWrite(PIN_SHIFT_DATA, LOW);
  digitalWrite(PIN_SHIFT_CLOCK, LOW);
  digitalWrite(PIN_SHIFT_LATCH, LOW);
  digitalWrite(PIN_DECADE_RESET, LOW);
  digitalWrite(PIN_DECADE_CLOCK, LOW);

  for (int i = 0; i < ROWS; i++) {
    for (int j = COLUMNS - 1; j >= 0; j--) {
      digitalWrite(PIN_SHIFT_DATA, text[i][j] ? HIGH : LOW);
      digitalWrite(PIN_SHIFT_CLOCK, HIGH);
      digitalWrite(PIN_SHIFT_CLOCK, LOW);
    b}

    if (i != 0) digitalWrite(PIN_DECADE_CLOCK, HIGH);
    digitalWrite(PIN_SHIFT_LATCH, HIGH);
    
    digitalWrite(PIN_SHIFT_LATCH, LOW);
    digitalWrite(PIN_DECADE_CLOCK, LOW);
  }
}

void setup() {
  pinMode(PIN_SHIFT_DATA, OUTPUT);
  pinMode(PIN_SHIFT_CLOCK, OUTPUT);
  pinMode(PIN_SHIFT_LATCH, OUTPUT);

  pinMode(PIN_DECADE_RESET, OUTPUT);
  pinMode(PIN_DECADE_CLOCK, OUTPUT);

  // Init Screen
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      screen[i][j] = false;
    }
  }

  // Test Screen
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      screen[i][j] = (i + j) % 2 == 0;
    }
  }
}

void loop() {
  draw();
}
