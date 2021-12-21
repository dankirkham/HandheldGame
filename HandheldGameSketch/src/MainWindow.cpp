#include "MainWindow.h"

#include "Brick.h"
#include "Constants.h"
#include "MainWindow.h"
#include "Pins.h"
#include "Screen.h"
#include "Snek.h"

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

    screen->draw();
    auto buf = screen->getBuffer();

    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLUMNS; j++) {
        auto color = *(buf + i * COLUMNS + j) ? Qt::green : Qt::gray;
        p.setBrush(color);

        p.drawRect(
          j * SQUARE_SPACING + (SQUARE_SPACING - SQUARE_SIZE) / 2,
          i * SQUARE_SPACING + (SQUARE_SPACING - SQUARE_SIZE) / 2,
          SQUARE_SIZE,
          SQUARE_SIZE);
      }
    }
  }
public:
  Matrix(QWidget * parent = 0) : QWidget(parent) {}

  void setScreen(Screen* s)
  {
    screen = s;
  }
private:
  Screen* screen;
};


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
  counter = 1;
  input_counter = 1;
  display_counter = 1;

  input = new Input();
  Screen *screen = new Screen();
  Snek* snek = new Snek(screen, input);
  Brick* brick = new Brick(screen, input);
  game = brick;

  Matrix* t = new Matrix(this);
  t->setScreen(screen);

  setCentralWidget(t);

  this->setMinimumSize(COLUMNS * SQUARE_SPACING, ROWS * SQUARE_SPACING);
  this->setWindowTitle("Handheld Game");

  timerId = startTimer(1);
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
    input->keyPressEvent(PIN_BUTTON_LEFT);
  }
  else if (key == Qt::Key_S || key == Qt::Key_Down)
  {
    input->keyPressEvent(PIN_BUTTON_DOWN);
  }
  else if (key == Qt::Key_D || key == Qt::Key_Right)
  {
    input->keyPressEvent(PIN_BUTTON_RIGHT);
  }
  else if (key == Qt::Key_W || key == Qt::Key_Up)
  {
    input->keyPressEvent(PIN_BUTTON_UP);
  }
  else if (key == Qt::Key_Z || key == Qt::Key_Comma)
  {
    input->keyPressEvent(PIN_BUTTON_A);
  }
  else if (key == Qt::Key_X || key == Qt::Key_Period)
  {
    input->keyPressEvent(PIN_BUTTON_B);
  }
  else if (key == Qt::Key_Enter || key == Qt::Key_Return)
  {
    input->keyPressEvent(PIN_BUTTON_START);
  }
  else if (key == Qt::Key_Shift)
  {
    input->keyPressEvent(PIN_BUTTON_SELECT);
  }
}

void MainWindow::keyReleaseEvent(QKeyEvent* event)
{
  auto key = event->key();
  if (key == Qt::Key_A || key == Qt::Key_Left)
  {
    input->keyReleaseEvent(PIN_BUTTON_LEFT);
  }
  else if (key == Qt::Key_S || key == Qt::Key_Down)
  {
    input->keyReleaseEvent(PIN_BUTTON_DOWN);
  }
  else if (key == Qt::Key_D || key == Qt::Key_Right)
  {
    input->keyReleaseEvent(PIN_BUTTON_RIGHT);
  }
  else if (key == Qt::Key_W || key == Qt::Key_Up)
  {
    input->keyReleaseEvent(PIN_BUTTON_UP);
  }
  else if (key == Qt::Key_Z || key == Qt::Key_Comma)
  {
    input->keyReleaseEvent(PIN_BUTTON_A);
  }
  else if (key == Qt::Key_X || key == Qt::Key_Period)
  {
    input->keyReleaseEvent(PIN_BUTTON_B);
  }
  else if (key == Qt::Key_Enter || key == Qt::Key_Return)
  {
    input->keyReleaseEvent(PIN_BUTTON_START);
  }
  else if (key == Qt::Key_Shift)
  {
    input->keyReleaseEvent(PIN_BUTTON_SELECT);
  }
}

void MainWindow::timerEvent(QTimerEvent *event)
{
  counter--;
  if (counter == 0) {
    counter = game->getDelay();
    game->tick();

    centralWidget()->update();
  }

  //input_counter--;
  //if (input_counter == 0) {
  //  input_counter = Input::DELAY;
  //  input->tick();
  //}

  //display_counter--;
  //if (display_counter == 0) {
  //  display_counter = 20;
  //}
}
