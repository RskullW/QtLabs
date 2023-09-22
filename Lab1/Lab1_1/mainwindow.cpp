#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSizePolicy>
#include <QScrollBar>
#include <QFrame>
#include <QSpacerItem>
#include <QMenuBar>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Render();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Render() {
    QWidget* centralWidget = new QWidget(this);
    QGridLayout *layout = new QGridLayout(this);
    QHBoxLayout *horizontalLayout1 = new QHBoxLayout(this);
    QVBoxLayout *verticalLayout2 = new QVBoxLayout(this);
    QHBoxLayout *horizontalLayout3 = new QHBoxLayout(this);

    layout->addItem(horizontalLayout1, 0, 0);
    layout->addItem(verticalLayout2, 1, 0);
    layout->addItem(horizontalLayout3, 2, 0);
    layout->setRowStretch(0, 10);
    RenderHorizontalLayout1(horizontalLayout1);
    RenderVerticalLayout2(verticalLayout2);
    RenderHorizontalLayout3(horizontalLayout3);

    centralWidget->setStyleSheet("background-color: rgb(190, 190, 190)");
    centralWidget->setLayout(layout);
    centralWidget->setMinimumSize(QSize(640, 480));
    centralWidget->setMaximumSize(QSize(1920, 1080));
    centralWidget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    QMenuBar* menuBar = new QMenuBar(this);
    setMenuBar(menuBar);

    menuBar->addMenu("File");
    menuBar->addMenu("Edit");
    menuBar->addMenu("View");
    menuBar->addMenu("Image");
    menuBar->addMenu("Options");
    menuBar->addMenu("Help");

    setCentralWidget(centralWidget);
}

void MainWindow::RenderHorizontalLayout1(QHBoxLayout *horizontalLayout1) {
    {
        QHBoxLayout* menu = new QHBoxLayout(this);
        QGridLayout* gridLayout = new QGridLayout(this);
        QFrame* frame11 = new QFrame(this);
        frame11->setFrameShape(QFrame::Shape::Panel);
        frame11->setFrameShadow(QFrame::Shadow::Sunken);
        frame11->setLineWidth(1);
        frame11->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        {
            gridLayout->addLayout(createHorizontalLayoutForButton(
                                      "image: url(:/img/C:/Users/mailc/Downloads/Telegram Desktop/photo_4_2023-08-31_12-50-55.jpg);",
                                      "image: url(:/img/C:/Users/mailc/Downloads/Telegram Desktop/photo_2_2023-08-31_12-50-55.jpg);"),
                                  0, 0);
            gridLayout->addLayout(createHorizontalLayoutForButton(
                                      "image: url(:/img/C:/Users/mailc/Downloads/Telegram Desktop/photo_11_2023-08-31_12-50-55.jpg);",
                                      "image: url(:/img/C:/Users/mailc/Downloads/Telegram Desktop/photo_10_2023-08-31_12-50-55.jpg);"),
                                  1, 0);
            gridLayout->addLayout(createHorizontalLayoutForButton(
                                      "image: url(:/img/C:/Users/mailc/Downloads/Telegram Desktop/photo_8_2023-08-31_12-50-55.jpg);",
                                      "image: url(:/img/C:/Users/mailc/Downloads/Telegram Desktop/photo_5_2023-08-31_12-50-55.jpg);"),
                                  2, 0);
            gridLayout->addLayout(createHorizontalLayoutForButton(
                                      "image: url(:/img/C:/Users/mailc/Downloads/Telegram Desktop/photo_13_2023-08-31_12-50-55.jpg);",
                                      "image: url(:/img/C:/Users/mailc/Downloads/Telegram Desktop/photo_9_2023-08-31_12-50-55.jpg);"),
                                  3, 0);
            gridLayout->addLayout(createHorizontalLayoutForButton(
                                      "image: url(:/img/C:/Users/mailc/Downloads/Telegram Desktop/photo_7_2023-08-31_12-50-55.jpg);",
                                      "image: url(:/img/C:/Users/mailc/Downloads/Telegram Desktop/photo_12_2023-08-31_12-50-55.jpg);"),
                                  4, 0);
            gridLayout->addLayout(createHorizontalLayoutForButton(
                                      "image: url(:/img/C:/Users/mailc/Downloads/Telegram Desktop/photo_1_2023-08-31_12-50-55.jpg);\n\n",
                                      "image: url(:/img/C:/Users/mailc/Downloads/Telegram Desktop/photo_3_2023-08-31_12-50-55.jpg);"),
                                  5, 0);
            gridLayout->addLayout(createHorizontalLayoutForButton(
                                      "image: url(:/img/C:/Users/mailc/Downloads/Telegram Desktop/photo_14_2023-08-31_12-50-55.jpg);",
                                      "image: url(:/img/C:/Users/mailc/Downloads/Telegram Desktop/photo_15_2023-08-31_12-50-55.jpg);"),
                                  6, 0);
            gridLayout->addLayout(createHorizontalLayoutForButton(
                                      "image: url(:/img/C:/Users/mailc/Downloads/Telegram Desktop/photo_16_2023-08-31_12-50-55.jpg);",
                                      "image: url(:/img/C:/Users/mailc/Downloads/Telegram Desktop/photo_6_2023-08-31_12-50-55.jpg);"),
                                  7, 0);
        }

        gridLayout->addWidget(frame11, 8, 0);
        menu->addLayout(gridLayout);
        horizontalLayout1->addLayout(menu);
    }
    {
        QHBoxLayout* background = new QHBoxLayout(this);
        QGridLayout* gridLayout = new QGridLayout(this);
        QFrame* frame = new QFrame(this);
        QScrollBar* horizontalScroll = new QScrollBar(this);
        QScrollBar* verticalScroll = new QScrollBar(this);

        horizontalScroll->setOrientation(Qt::Horizontal);
        verticalScroll->setOrientation(Qt::Vertical);

        frame->setStyleSheet("background-image: url(:/img/C:/Users/mailc/Downloads/Telegram Desktop/Ev72ATUHthI.png);");
        frame->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

        gridLayout->addWidget(frame, 0, 0);
        gridLayout->addWidget(horizontalScroll, 1, 0);
        gridLayout->addWidget(verticalScroll, 0, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 0);

        background->addLayout(gridLayout);
        horizontalLayout1->addLayout(background);
    }
}

QHBoxLayout* MainWindow::createHorizontalLayoutForButton(QString styleSheet1, QString styleSheet2) {
    QHBoxLayout* horizontalLayout = new QHBoxLayout(this);
    QPushButton* pushButton1 = new QPushButton(this);
    QPushButton* pushButton2 = new QPushButton(this);

    pushButton1->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
    pushButton2->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);

    pushButton1->setMinimumSize(5, 5);
    pushButton2->setMinimumSize(5, 5);

    pushButton1->setStyleSheet(styleSheet1);
    pushButton2->setStyleSheet(styleSheet2);

    horizontalLayout->addWidget(pushButton1);
    horizontalLayout->addWidget(pushButton2);

    return horizontalLayout;


}

QPushButton* MainWindow::createButton(QString styleSheet) {
    QPushButton* pushButton = new QPushButton();
    pushButton->setStyleSheet(styleSheet);
    pushButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    return pushButton;

}
void MainWindow::RenderVerticalLayout2(QVBoxLayout *verticalLayout2) {
    QFrame* selectorFrame = new QFrame(this);
    QFrame* frame9 = new QFrame(selectorFrame);
    QGridLayout* selectorColor = new QGridLayout(selectorFrame);

    frame9->setFrameShape(QFrame::Shape::Panel);
    frame9->setFrameShadow(QFrame::Shadow::Sunken);
    frame9->setLineWidth(1);
    frame9->setStyleSheet("background-color: rgb(210, 210, 210);");


    {
        QVBoxLayout* layout = new QVBoxLayout(frame9);
        layout->setSpacing(6);
        layout->setStretch(0, 1);
        layout->setStretch(1, 1);

        layout->addWidget(createButton("QPushButton {\n    background-color: black;\n}\n\nQPushButton:pressed {\n    background-color: rgb(100, 100, 100);\n}\n"));
        layout->addWidget(createButton("QPushButton {\n    background-color: white;\n}\n\nQPushButton:pressed {\n    background-color: rgb(100, 100, 100);\n}\n"));
    }

    {
        selectorColor->addWidget(createButton("QPushButton {\n    background-color: black;\n}\n\nQPushButton:pressed {\n    background-color: rgb(100, 100, 100);\n}\n"), 0, 1);
        selectorColor->addWidget(createButton("QPushButton {\n    background-color: rgb(98, 98, 98);\n}\n\nQPushButton:pressed {\n    background-color: rgb(100, 100, 100);\n}\n"), 0, 2);
        selectorColor->addWidget(createButton("QPushButton {\n    background-color: rgb(85, 0, 0);\n}\n\nQPushButton:pressed {\n    background-color: rgb(100, 100, 100);\n}\n"), 0, 3);
        selectorColor->addWidget(createButton("QPushButton {\n    background-color: rgb(85, 85, 0);\n}\n\nQPushButton:pressed {\n    background-color: rgb(100, 100, 100);\n}\n"), 0, 4);
        selectorColor->addWidget(createButton("QPushButton {\n    background-color: rgb(0, 85, 0);\n}\n\nQPushButton:pressed {\n    background-color: rgb(100, 100, 100);\n}\n"), 0, 5);
        selectorColor->addWidget(createButton("QPushButton {\n    background-color: rgb(85, 85, 127);\n}\n\nQPushButton:pressed {\n    background-color: rgb(100, 100, 100);\n}\n"), 0, 6);
        selectorColor->addWidget(createButton("QPushButton {\n    background-color: rgb(0, 0, 127);\n}\n\nQPushButton:pressed {\n    background-color: rgb(100, 100, 100);\n}\n"), 0, 7);
        selectorColor->addWidget(createButton("QPushButton {\n    background-color: rgb(170, 0, 127);\n}\n\nQPushButton:pressed {\n    background-color: rgb(100, 100, 100);\n}\n"), 0, 8);
        selectorColor->addWidget(createButton("QPushButton {\n    background-color: rgb(138, 138, 0);\n}\n\nQPushButton:pressed {\n    background-color: rgb(100, 100, 100);\n}\n"), 0, 9);
        selectorColor->addWidget(createButton("QPushButton {\n    background-color: rgb(0, 43, 63);\n}\n\nQPushButton:pressed {\n    background-color: rgb(100, 100, 100);\n}\n"), 0, 10);
        selectorColor->addWidget(createButton("QPushButton {\n    background-color: rgb(0, 85, 255);\n}\n\nQPushButton:pressed {\n    background-color: rgb(100, 100, 100);\n}\n"), 0, 11);
        selectorColor->addWidget(createButton("QPushButton {\n    background-color: rgb(0, 24, 71);\n}\n\nQPushButton:pressed {\n    background-color: rgb(100, 100, 100);\n}\n"), 0, 12);
        selectorColor->addWidget(createButton("QPushButton {\n    background-color: rgb(85, 85, 255);\n}\n\nQPushButton:pressed {\n    background-color: rgb(100, 100, 100);\n}\n"), 0, 13);
        selectorColor->addWidget(createButton("QPushButton {\n    background-color: rgb(170, 85, 0);\n}\n\nQPushButton:pressed {\n    background-color: rgb(100, 100, 100);\n}\n"), 0, 14);

        selectorColor->addWidget(createButton("QPushButton {\n    background-color: white;\n}\n\nQPushButton:pressed {\n    background-color: rgb(100, 100, 100);\n}\n"), 1, 1);
        selectorColor->addWidget(createButton("QPushButton {\n    background-color: grey;\n}\n\nQPushButton:pressed {\n    background-color: rgb(100, 100, 100);\n}\n"), 1, 2);
        selectorColor->addWidget(createButton("QPushButton {\n    background-color: rgb(255, 0, 0);\n}\n\nQPushButton:pressed {\n    background-color: rgb(100, 100, 100);\n}\n"), 1, 3);
        selectorColor->addWidget(createButton("QPushButton {\n    background-color: rgb(255, 255, 0);\n}\n\nQPushButton:pressed {\n    background-color: rgb(100, 100, 100);\n}\n"), 1, 4);
        selectorColor->addWidget(createButton("QPushButton {\n    background-color: rgb(0, 255, 0);\n}\n\nQPushButton:pressed {\n    background-color: rgb(100, 100, 100);\n}\n"), 1, 5);
        selectorColor->addWidget(createButton("QPushButton {\n    background-color: rgb(0, 255, 255);\n}\n\nQPushButton:pressed {\n    background-color: rgb(100, 100, 100);\n}\n"), 1, 6);
        selectorColor->addWidget(createButton("QPushButton {\n    background-color: rgb(85, 85, 255);\n}\n\nQPushButton:pressed {\n    background-color: rgb(100, 100, 100);\n}\n"), 1, 7);
        selectorColor->addWidget(createButton("QPushButton {\n    background-color: rgb(255, 85, 255);\n}\n\nQPushButton:pressed {\n    background-color: rgb(100, 100, 100);\n}\n"), 1, 8);
        selectorColor->addWidget(createButton("QPushButton {\n    background-color: rgb(255, 255, 127);\n}\n\nQPushButton:pressed {\n    background-color: rgb(100, 100, 100);\n}\n"), 1, 9);
        selectorColor->addWidget(createButton(""), 1, 10);
        selectorColor->addWidget(createButton("QPushButton {\n    background-color: rgb(85, 255, 255);\n}\n\nQPushButton:pressed {\n    background-color: rgb(100, 100, 100);\n}\n"), 1, 11);
        selectorColor->addWidget(createButton("QPushButton {\n    background-color: rgb(170, 85, 255);\n}\n\nQPushButton:pressed {\n    background-color: rgb(100, 100, 100);\n}\n"), 1, 12);
        selectorColor->addWidget(createButton("QPushButton {\n    background-color: rgb(255, 0, 127);\n}\n\nQPushButton:pressed {\n    background-color: rgb(100, 100, 100);\n}\n"), 1, 13);
        selectorColor->addWidget(createButton("QPushButton {\n    background-color: rgb(255, 170, 0);\n}\n\nQPushButton:pressed {\n    background-color: rgb(100, 100, 100);\n}\n"), 1, 14);

    }

    selectorColor->setVerticalSpacing(6);
    selectorColor->setHorizontalSpacing(6);
    selectorColor->setContentsMargins(QMargins(9, 9, 9, 9));
    verticalLayout2->setSpacing(6);
    verticalLayout2->addWidget(selectorFrame);
}

void MainWindow::RenderHorizontalLayout3(QHBoxLayout *horizontalLayout3) {
    QFrame* frame5 = createFrame();
    QFrame* frame6 = createFrame();
    QFrame* frame7 = createFrame();
    QFrame* frame8 = createFrame();

    {
        QLabel* label = new QLabel("For Help, click Help Topics on the Help Menu.", frame5);
        label->setStyleSheet("color: rgb(0, 0, 0);");
    }

    {
        createFrameFromImage("image: url(:/img/C:/Users/mailc/Downloads/Telegram Desktop/photo_2_2023-08-31_13-23-22.jpg);", frame6);
        createFrameFromImage("image: url(:/img/C:/Users/mailc/Downloads/Telegram Desktop/photo_3_2023-08-31_13-23-22.jpg);", frame7);
        createFrameFromImage("image: url(:/img/C:/Users/mailc/Downloads/Telegram Desktop/photo_1_2023-08-31_13-23-22.jpg);", frame8);

    }
    horizontalLayout3->addWidget(frame5);
    horizontalLayout3->addWidget(frame6);
    horizontalLayout3->addWidget(frame7);
    horizontalLayout3->addWidget(frame8);

}


QFrame* MainWindow::createFrame() {
    QFrame* frame = new QFrame(this);
    QGridLayout* layout = new QGridLayout(frame);

    layout->setContentsMargins(QMargins(9,9,9,9));
    layout->setHorizontalSpacing(6);
    layout->setVerticalSpacing(6);

    frame->setLayout(layout);

    frame->setFrameShadow(QFrame::Shadow::Sunken);
    frame->setFrameShape(QFrame::Shape::Panel);
    frame->setLineWidth(1);

    return frame;
}

void MainWindow::createFrameFromImage(QString styleSheet, QWidget* parentWidget) {
    QFrame* frame = new QFrame(parentWidget);

    frame->setFrameShadow(QFrame::Shadow::Raised);
    frame->setFrameShape(QFrame::Shape::NoFrame);
    frame->setStyleSheet(styleSheet);
    frame->setLineWidth(1);

    QSpacerItem* spacerHorizontal = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Preferred);
    parentWidget->layout()->addItem(spacerHorizontal);
}
