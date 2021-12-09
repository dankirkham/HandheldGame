#ifndef ARDUINO
#include <iostream>

#include <QApplication>
#include <QMainWindow>
#include <QPainter>

#include "Pins.h"

const int SQUARE_SIZE = 40;
const int SQUARE_SPACING = 50;

class Top : public QWidget {
  void paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.setPen(Qt::NoPen);

    for (int i = 0; i < 16; i++) {
      for (int j = 0; j < 10; j++) {
        if ((i + j) % 2 == 0) {
          p.setBrush(Qt::green);
        } else {
          p.setBrush(Qt::gray);
        }
        p.drawRect(
          i * SQUARE_SPACING + (SQUARE_SPACING - SQUARE_SIZE) / 2,
          j * SQUARE_SPACING + (SQUARE_SPACING - SQUARE_SIZE) / 2,
          SQUARE_SIZE,
          SQUARE_SIZE);
      }
    }
  }
public:
  Top(QWidget * parent = 0) : QWidget(parent) {}
};

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  QMainWindow mw;
  Top t;
  mw.setCentralWidget(&t);
  mw.setMinimumSize(1600 / 2, 1000 / 2);
  mw.setWindowTitle("Handheld Game");
  mw.show();
  return a.exec();
}

#endif
