#include "drawingscene.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DrawingScene scene;
    scene.setSceneRect(0, 0, 800, 600);

    QGraphicsView view(&scene);
    view.setWindowTitle("Рисование линий");
    view.show();

    QMenu menu;
    QAction *method1Action = menu.addAction("Метод 1");
    QAction *method2Action = menu.addAction("Метод 2");

    QObject::connect(method1Action, &QAction::triggered, [&scene]() { scene.setDrawMethod(0); });
    QObject::connect(method2Action, &QAction::triggered, [&scene]() { scene.setDrawMethod(1); });

    QPushButton methodButton("Выбрать метод");
    QObject::connect(&methodButton, &QPushButton::clicked, [&menu, &methodButton]() {
        menu.exec(methodButton.mapToGlobal(QPoint(0, methodButton.height())));
    });

    QPushButton colorButton("Выбрать цвет");
    QObject::connect(&colorButton, &QPushButton::clicked, [&scene]() { scene.setDrawColor(); });

    QPushButton widthPenButton("Выбрать размер кисти");
    QObject::connect(&widthPenButton, &QPushButton::clicked, [&scene]() { scene.setDrawWidth(); });

    QListWidget listWidget;

    scene.setListWidget(&listWidget);

    QObject::connect(&listWidget, &QListWidget::itemDoubleClicked, [&scene](QListWidgetItem *item) {
        scene.removeObjectFromList(item);
    });

    QPushButton removeAllLinesButton("Удалить все линии");
    QObject::connect(&removeAllLinesButton, &QPushButton::clicked, [&scene]() {scene.removeAllLines();});

    QPushButton selectLine("Выбрать линию");
    QObject::connect(&selectLine, &QPushButton::clicked, [&scene]() {scene.selectLine();});

    QVBoxLayout layout;
    layout.addWidget(&view);
    layout.addWidget(&methodButton);
    layout.addWidget(&colorButton);
    layout.addWidget(&widthPenButton);
    layout.addWidget(&selectLine);
    layout.addWidget(&listWidget);
    layout.addWidget(&removeAllLinesButton);

    QWidget widget;
    widget.setLayout(&layout);
    widget.setMouseTracking(true);
    widget.show();


    return a.exec();
}
