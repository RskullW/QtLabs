#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QListView>
#include "taskmodel.h"
#include "memorydisplaywidget.h"
#include "memorymanager.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    void start(int countTask, int sizeOfBytes);
    void setCountTasks(int countTask);
    void setCountSizeOfBytes(int sizeOfBytes);

    void generateTasks();
    void renderButtons(QVBoxLayout* layout);
private slots:
    void updateSystem();
private:
    int maxTasks;
    int sizeOfBytes;
    MemoryManager* memoryManager;
    TaskModel taskModel;
    QListView *taskListView;
    MemoryDisplayWidget *memoryDisplayWidget;
};
#endif // MAINWINDOW_H
