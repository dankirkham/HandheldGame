#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "Game.h"
#include "Input.h"
#include "Brick.h"
#include "Menu.h"
#include "Snek.h"
#include "Birb.h"

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
  Input* input;

  Menu* menu;
  Snek* snek;
  Brick* brick;
  Game* game;
  Birb* birb;

protected:
  void keyPressEvent(QKeyEvent*);
  void keyReleaseEvent(QKeyEvent*);
  void timerEvent(QTimerEvent *event);
};

#endif // MAINWINDOW_H

