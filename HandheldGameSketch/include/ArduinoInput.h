#ifndef ArduinoInput_h
#define ArduinoInput_h

// Don't include directly, include Input.h instead.

class Input : public IInput {
public:
  bool keyDown(button_e key) override;

  void handleB();
  void handleC();
};

#endif
