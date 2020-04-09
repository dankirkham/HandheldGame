#ifndef Input_h
#define Input_h

class Input {
private:
  static const int DEBOUNCE_COUNT = 4;

  bool start_pressed;
  bool select_pressed;
  bool a_pressed;
  bool b_pressed;
  bool up_pressed;
  bool left_pressed;
  bool down_pressed;
  bool right_pressed;

  int start_debounce_count = 0;
  int select_debounce_count = 0;
  int a_debounce_count = 0;
  int b_debounce_count = 0;
  int up_debounce_count = 0;
  int left_debounce_count = 0;
  int down_debounce_count = 0;
  int right_debounce_count = 0;
public:
  static const int DELAY = 5;

  Input();
  bool keyDown(int key);
  void handleB();
  void handleC();
  void tick();
};

#endif
