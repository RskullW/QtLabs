#ifndef TASKMODEL_H
#define TASKMODEL_H

#include <QAbstractListModel>
#include <QList>
#include "task.h"

class TaskModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum TaskRoles {
        NameRole = Qt::UserRole + 1,
        SizeInBytesRole,
        MaxStartTimeRole,
        DurationRole,
        StatusRole,
        IdRole,
        SerializeTask,
    };

    TaskModel(QObject* parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    Task* getTask(int index);
    // Методы для добавления, удаления и обновления задач
    void addTask(Task* task);
    void removeTask(int index);
    void clearTasks();
    Task* deserializeTask(const QString& serializedTask);

private:
    QList<Task*> tasks;

    QString serializeTask(const Task& task) const;


};

#endif // TASKMODEL_H
