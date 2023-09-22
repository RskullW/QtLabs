#include "mainwindow.h"
#include "computerconfigurator.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ComputerConfigurator configurator;
    configurator.show();

    return app.exec();
}
