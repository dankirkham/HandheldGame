#include "MainWindow.h"

#include "Constants.h"
#include "MainWindow.h"
#include "Pins.h"
#include "Executor.h"

#include <iostream>
#include <QDebug>
#include <QPainter>
#include <QVBoxLayout>
#include <QKeyEvent>

const int SQUARE_SIZE = 40;
const int SQUARE_SPACING = 50;

class Matrix : public QWidget {
  void paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.setPen(Qt::NoPen);

    Executor::screen->draw();

    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLUMNS; j++) {
        auto pixel = Executor::screen->getPixel(j, i);

        double r = (int)pixel / 3.0;
        //std ::cout << (int)pixel << std::endl;
        auto gray = QColor(Qt::gray);
        auto green = QColor(Qt::green);
        QColor color(
          gray.red() * (1-r) + green.red() * r,
          gray.green() * (1-r) + green.green() * r,
          gray.blue() * (1-r) + green.blue() * r,
          255);

        p.setBrush(color);

        p.drawEllipse(
          j * SQUARE_SPACING + (SQUARE_SPACING - SQUARE_SIZE) / 2,
          i * SQUARE_SPACING + (SQUARE_SPACING - SQUARE_SIZE) / 2,
          SQUARE_SIZE,
          SQUARE_SIZE);
      }
    }
  }
public:
  Matrix(QWidget * parent = 0) : QWidget(parent) {}
};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
  Matrix* t = new Matrix(this);

  setCentralWidget(t);

  this->setMinimumSize(COLUMNS * SQUARE_SPACING, ROWS * SQUARE_SPACING);
  this->setWindowTitle("Handheld Game");

  timerId = startTimer(2);
}

MainWindow::~MainWindow()
{
  killTimer(timerId);
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
  auto key = event->key();
  if (key == Qt::Key_A || key == Qt::Key_Left)
  {
    Executor::input->keyPressEvent(button_e::left);
  }
  else if (key == Qt::Key_S || key == Qt::Key_Down)
  {
    Executor::input->keyPressEvent(button_e::down);
  }
  else if (key == Qt::Key_D || key == Qt::Key_Right)
  {
    Executor::input->keyPressEvent(button_e::right);
  }
  else if (key == Qt::Key_W || key == Qt::Key_Up)
  {
    Executor::input->keyPressEvent(button_e::up);
  }
  else if (key == Qt::Key_Z || key == Qt::Key_Comma)
  {
    Executor::input->keyPressEvent(button_e::a);
  }
  else if (key == Qt::Key_X || key == Qt::Key_Period)
  {
    Executor::input->keyPressEvent(button_e::b);
  }
  else if (key == Qt::Key_Enter || key == Qt::Key_Return)
  {
    Executor::input->keyPressEvent(button_e::start);
  }
  else if (key == Qt::Key_Shift)
  {
    Executor::input->keyPressEvent(button_e::select);
  }
}

void MainWindow::keyReleaseEvent(QKeyEvent* event)
{
  auto key = event->key();
  if (key == Qt::Key_A || key == Qt::Key_Left)
  {
    Executor::input->keyReleaseEvent(button_e::left);
  }
  else if (key == Qt::Key_S || key == Qt::Key_Down)
  {
    Executor::input->keyReleaseEvent(button_e::down);
  }
  else if (key == Qt::Key_D || key == Qt::Key_Right)
  {
    Executor::input->keyReleaseEvent(button_e::right);
  }
  else if (key == Qt::Key_W || key == Qt::Key_Up)
  {
    Executor::input->keyReleaseEvent(button_e::up);
  }
  else if (key == Qt::Key_Z || key == Qt::Key_Comma)
  {
    Executor::input->keyReleaseEvent(button_e::a);
  }
  else if (key == Qt::Key_X || key == Qt::Key_Period)
  {
    Executor::input->keyReleaseEvent(button_e::b);
  }
  else if (key == Qt::Key_Enter || key == Qt::Key_Return)
  {
    Executor::input->keyReleaseEvent(button_e::start);
  }
  else if (key == Qt::Key_Shift)
  {
    Executor::input->keyReleaseEvent(button_e::select);
  }
}

void MainWindow::timerEvent(QTimerEvent *event)
{
  Executor::tick();
  centralWidget()->update();
}
