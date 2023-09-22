#include "mainwindow.h"
#include "taskdelegate.h"
#include <QPushButton>
#include <QTimer>
#include <QLineEdit>
#include <QSpinBox>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) {
    setCountTasks(0);
    setCountSizeOfBytes(0);
}

void MainWindow::setCountTasks(int countTask) {
    this->maxTasks = countTask;
}

void MainWindow::setCountSizeOfBytes(int sizeOfBytes) {
    this->sizeOfBytes = sizeOfBytes;
}

void MainWindow::start(int countTask, int sizeOfBytes) {
    setCountSizeOfBytes(sizeOfBytes);
    setCountTasks(countTask);

    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout;

    memoryManager = new MemoryManager(sizeOfBytes);
    taskListView = new QListView();

    taskListView->setModel(&taskModel);

    TaskDelegate* taskDelegate = new TaskDelegate(taskListView);

    taskListView->setItemDelegate(taskDelegate);

    generateTasks();

    memoryDisplayWidget = new MemoryDisplayWidget();
    memoryDisplayWidget->updateMemory(memoryManager->getMemoryState());


    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [=] {
        taskListView->viewport()->update();
        updateSystem();
    });

    timer->start(1000);

    layout->addWidget(memoryDisplayWidget);
    layout->addWidget(taskListView);
    renderButtons(layout);
    centralWidget->setLayout(layout);

    setCentralWidget(centralWidget);
}

void MainWindow::renderButtons(QVBoxLayout* layout) {
    QSpinBox* taskCountSpinBox = new QSpinBox();

    QPushButton* pushButton = new QPushButton("Сгенерировать новые задачи", this);

    QObject::connect(pushButton, &QPushButton::clicked, [=] {
        setCountTasks(taskCountSpinBox->value());
        generateTasks();
    });

    layout->addWidget(new QLabel("Number of Tasks:"));
    layout->addWidget(taskCountSpinBox);
    layout->addWidget(pushButton);
}
void MainWindow::generateTasks()
{
    for (int i = 0; i < maxTasks; ++i) {

        QString name = "Задача" + QString::number(i);
        int size = rand() % sizeOfBytes + 1;
        int startTime = rand() % 10;
        int duration = rand() % 10 + 1;
        int taskId = rand()%100 + 1;

        Task* task = new Task(name, size, startTime, duration);
        task->setTaskId(taskId);
        task->setStatus(Task::Waiting);
        taskModel.addTask(task);

        task = nullptr;
    }
}

void MainWindow::updateSystem() {
    for (int i = 0; i < taskModel.rowCount(); ++i) {
        QModelIndex index = taskModel.index(i, 0);
        Task* task = taskModel.getTask(i);
        int startTime = index.data(TaskModel::MaxStartTimeRole).toInt();

        if (startTime > 0) {
            task->setMaxStartTime(startTime-1);
        }
    }

    for (int i = 0; i < taskModel.rowCount(); ++i) {
        QModelIndex index = taskModel.index(i, 0);
        Task* task = taskModel.getTask(i);
        int taskSize = index.data(TaskModel::SizeInBytesRole).toInt();
        int startTime = index.data(TaskModel::MaxStartTimeRole).toInt();

        if (startTime <= 0) {
            int allocatedMemory = memoryManager->allocateMemory(taskSize);
            if (allocatedMemory >= 0) {
                task->setTaskId(allocatedMemory);
                taskModel.removeTask(i);
                task->setStatus(Task::Running);
                taskModel.addTask(task);
            }
        }
    }

    for (int i = 0; i < taskModel.rowCount(); ++i) {
        QModelIndex index = taskModel.index(i, 0);
        Task* task = taskModel.getTask(i);
        int taskSize = index.data(TaskModel::SizeInBytesRole).toInt();
        int duration = index.data(TaskModel::DurationRole).toInt();

        if (duration > 0 && task->status() == Task::Running) {
            task->setDuration(duration-1);

        } else if (duration <= 0 && task->status() == Task::Running){
            task->setStatus(Task::Completed);
            taskModel.removeTask(i);
            memoryManager->deallocateMemory(task->taskId());
            qDebug() << "taskId: " << task->taskId();
        }
    }

    bool isTotalWait = true;

    for (int i = 0; i < taskModel.rowCount(); ++i) {
        QModelIndex index = taskModel.index(i,0);
        Task* task = taskModel.getTask(i);
        Task::TaskStatus taskStatus = task->status();

        if (taskStatus != Task::Waiting) {
            isTotalWait = false;
            break;
        }
    }

    if (isTotalWait) {
        memoryManager->clearMemory();
    }

    memoryDisplayWidget->updateMemory(memoryManager->getMemoryState());
    taskListView->update();
}
