#include "taskmodel.h"
#include <QIODevice>

TaskModel::TaskModel(QObject* parent)
    : QAbstractListModel(parent)
{}

int TaskModel::rowCount(const QModelIndex& parent) const
{
    if (parent.isValid())
        return 0;

    return tasks.size();
}

QVariant TaskModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
        return QVariant();

    Task* task = tasks[index.row()];

    switch (role) {
        case NameRole:
            return QVariant::fromValue(task->name());
        case SizeInBytesRole:
            return QVariant::fromValue(task->sizeInBytes());
        case MaxStartTimeRole:
            return QVariant::fromValue(task->maxStartTime());
        case DurationRole:
            return QVariant::fromValue(task->duration());
        case StatusRole:
            return QVariant::fromValue(task->status());
        case IdRole:
            return QVariant::fromValue(task->taskId());
        case SerializeTask:
            return serializeTask(*task);
        default:
            return QVariant();
    }
}


void TaskModel::addTask(Task* task)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    tasks.append(task);
    endInsertRows();
    QModelIndex newIndex = index(rowCount() - 1, 0);
    setData(newIndex, QVariant::fromValue(&tasks.last()), TaskRoles::NameRole);
}


QString TaskModel::serializeTask(const Task& task) const
{
    // Создаем объект QByteArray для хранения сериализованных данных
    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);

    // Сериализуем объект Task в поток
    stream << task.name() << task.sizeInBytes() << task.maxStartTime() << task.duration() << task.status();

    // Преобразуем данные в строку в формате Base64
    return QString(data.toBase64());
}

Task* TaskModel::deserializeTask(const QString& serializedTask)
{
    // Декодируем строку из Base64 обратно в QByteArray
    QByteArray data = QByteArray::fromBase64(serializedTask.toUtf8());

    Task* task = nullptr;

    QDataStream stream(&data, QIODevice::ReadOnly);

    QString name;

    stream >> name;

    for (int i = 0; i < tasks.size(); ++i) {
        if (tasks[i]->name() == name) {
            task = tasks[i];
            break;
        }
    }

    return task;
}

void TaskModel::removeTask(int index)
{
    if (index < 0 || index >= tasks.size())
        return;

    beginRemoveRows(QModelIndex(), index, index);
    tasks.removeAt(index);
    endRemoveRows();
}

void TaskModel::clearTasks()
{
    if (!tasks.isEmpty()) {
        beginRemoveRows(QModelIndex(), 0, tasks.size() - 1);
        tasks.clear();
        endRemoveRows();
    }
}

Task* TaskModel::getTask(int index) {
    return tasks[index];
}

