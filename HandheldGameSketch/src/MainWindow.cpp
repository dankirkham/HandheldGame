#include "MainWindow.h"

#include "Constants.h"
#include "MainWindow.h"
#include "Pins.h"
#include "Screen.h"

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

    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLUMNS; j++) {
        //auto color = *(buf + i * COLUMNS + j) ? Qt::green : Qt::gray;
        auto color = screen->getPixel(j, i) ? Qt::green : Qt::gray;
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

  snek = new Snek(screen, input);
  menu = new Menu(screen, input);
  brick = new Brick(screen, input);
  birb = new Birb(screen, input);
  counter_game = new Counter(screen, input);

  game = menu;

  Matrix* t = new Matrix(this);
  t->setScreen(screen);

  setCentralWidget(t);

  this->setMinimumSize(COLUMNS * SQUARE_SPACING, ROWS * SQUARE_SPACING);
  this->setWindowTitle("Handheld Game");

  timerId = startTimer(6);
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
    input->keyPressEvent(button_e::left);
  }
  else if (key == Qt::Key_S || key == Qt::Key_Down)
  {
    input->keyPressEvent(button_e::down);
  }
  else if (key == Qt::Key_D || key == Qt::Key_Right)
  {
    input->keyPressEvent(button_e::right);
  }
  else if (key == Qt::Key_W || key == Qt::Key_Up)
  {
    input->keyPressEvent(button_e::up);
  }
  else if (key == Qt::Key_Z || key == Qt::Key_Comma)
  {
    input->keyPressEvent(button_e::a);
  }
  else if (key == Qt::Key_X || key == Qt::Key_Period)
  {
    input->keyPressEvent(button_e::b);
  }
  else if (key == Qt::Key_Enter || key == Qt::Key_Return)
  {
    input->keyPressEvent(button_e::start);
  }
  else if (key == Qt::Key_Shift)
  {
    input->keyPressEvent(button_e::select);
  }
}

void MainWindow::keyReleaseEvent(QKeyEvent* event)
{
  auto key = event->key();
  if (key == Qt::Key_A || key == Qt::Key_Left)
  {
    input->keyReleaseEvent(button_e::left);
  }
  else if (key == Qt::Key_S || key == Qt::Key_Down)
  {
    input->keyReleaseEvent(button_e::down);
  }
  else if (key == Qt::Key_D || key == Qt::Key_Right)
  {
    input->keyReleaseEvent(button_e::right);
  }
  else if (key == Qt::Key_W || key == Qt::Key_Up)
  {
    input->keyReleaseEvent(button_e::up);
  }
  else if (key == Qt::Key_Z || key == Qt::Key_Comma)
  {
    input->keyReleaseEvent(button_e::a);
  }
  else if (key == Qt::Key_X || key == Qt::Key_Period)
  {
    input->keyReleaseEvent(button_e::b);
  }
  else if (key == Qt::Key_Enter || key == Qt::Key_Return)
  {
    input->keyReleaseEvent(button_e::start);
  }
  else if (key == Qt::Key_Shift)
  {
    input->keyReleaseEvent(button_e::select);
  }
}

void MainWindow::timerEvent(QTimerEvent *event)
{
  counter--;
  if (counter == 0) {
    counter = game->getDelay();
    game->tick();

    centralWidget()->update();

    games_e nextGame = game->getGameToSwitchTo();

    switch (nextGame) {
      case games_e::SNEK:
        game = snek;
        break;
      case games_e::BRICK:
        game = brick;
        break;
      case games_e::BIRB:
        game = birb;
        break;
      case games_e::MENU:
        game = menu;
        break;
      case games_e::COUNTER:
        game = counter_game;
        break;
      default:
        break;
    }

    if (nextGame != games_e::NO_CHANGE) {
      game->init();
    }
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
