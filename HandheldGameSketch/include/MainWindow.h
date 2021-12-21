#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "Game.h"
#include "Input.h"

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private:
  int timerId;
  uint8_t counter;
  uint8_t input_counter;
  uint8_t display_counter;
  Game* game;
  Input* input;

protected:
  void keyPressEvent(QKeyEvent*);
  void keyReleaseEvent(QKeyEvent*);
  void timerEvent(QTimerEvent *event);
};

#endif // MAINWINDOW_H

