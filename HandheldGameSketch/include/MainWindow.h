#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private:
  int timerId;

protected:
  void keyPressEvent(QKeyEvent*);
  void keyReleaseEvent(QKeyEvent*);
  void timerEvent(QTimerEvent *event);
};

#endif // MAINWINDOW_H

