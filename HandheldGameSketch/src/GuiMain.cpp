#ifndef ARDUINO
#include <iostream>

#include <QApplication>

#include "MainWindow.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow mw;
  mw.show();

  return a.exec();
}

#endif
