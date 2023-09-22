#include "mainwindow.h"
#include "joysticklibrary.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    JoystickLibrary joystickLibrary;
    joystickLibrary.setFixedSize(320, 320);

    joystickLibrary.show();

    return a.exec();
}
