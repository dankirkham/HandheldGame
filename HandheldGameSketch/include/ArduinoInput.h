#ifndef ArduinoInput_h
#define ArduinoInput_h

// Don't include directly, include Input.h instead.

class Input : public IInput {
public:
  Input();
  bool keyDown(int key) override;
  void tick() override;

  void handleB();
  void handleC();
};

#endif
