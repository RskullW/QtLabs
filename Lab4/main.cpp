#include "mainwindow.h"

#include <QApplication>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QSpinBox>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QWidget* centralWidget = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout;

    QLineEdit* memorySizeEdit = new QLineEdit();
    QIntValidator* validator = new QIntValidator(memorySizeEdit);
    memorySizeEdit->setValidator(validator);

    QSpinBox* taskCountSpinBox = new QSpinBox();


    QPushButton* startButton = new QPushButton("Start");
    QObject::connect(startButton, &QPushButton::clicked, [&w, &memorySizeEdit, &taskCountSpinBox, &centralWidget]() {
        w.start(taskCountSpinBox->value(), memorySizeEdit->text().toInt());

        centralWidget->close();
        delete memorySizeEdit->validator();
        delete memorySizeEdit;
        delete taskCountSpinBox;
        delete centralWidget->layout();
        delete centralWidget;

        w.show();
    });
    layout->addWidget(new QLabel("Memory Size (bytes):"));
    layout->addWidget(memorySizeEdit);
    layout->addWidget(new QLabel("Number of Tasks:"));
    layout->addWidget(taskCountSpinBox);
    layout->addWidget(startButton);

    centralWidget->setLayout(layout);
    centralWidget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    centralWidget->setFixedSize(360, 180);
    centralWidget->show();

    return a.exec();
}

