#pragma once
#include <QStyledItemDelegate>
#include <QPainter>
#include "task.h"
#include "taskmodel.h"
#include <QIODevice>
#include <QByteArray>

class TaskDelegate : public QStyledItemDelegate
{
public:
    TaskDelegate(QObject* parent = nullptr) : QStyledItemDelegate(parent) {}

    void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override
    {
        if (!index.isValid())
            return;

        if (index.column() == 0) // Первая колонка
        {
            QString serializeText = index.data(TaskModel::SerializeTask).toString();
            Task* task = deserializeTask(serializeText);

            if (task)
            {
                QString statusText;
                switch (task->status()) {
                case Task::Running:
                    statusText = "Выполняется";
                    break;
                case Task::Waiting:
                    statusText = "Ожидание";
                    break;
                case Task::Completed:
                    statusText = "Завершен";
                    break;
                default:
                    statusText = "Неизвестно";
                    break;
                }

                QString text = QString("Name: %1 || Size: %2 || Start Time: %3 || Duration: %4 || Status: %5")
                                   .arg(task->name())
                                   .arg(task->sizeInBytes())
                                   .arg(task->maxStartTime())
                                   .arg(task->duration()).arg(statusText);

                painter->drawText(option.rect, text);
                return;
            }
        }

        // Если не получилось извлечь задачу, отображаем пустой текст
        QStyledItemDelegate::paint(painter, option, index);
        qDebug() << "Empty text in delegate";
    }

    Task* deserializeTask(const QString serializedTask) const
    {
        // Декодируем строку из Base64 обратно в QByteArray
        QByteArray data = QByteArray::fromBase64(serializedTask.toUtf8());

        QDataStream stream(&data, QIODevice::ReadOnly);

        QString name;
        Task::TaskStatus status;
        int sizeInBytes = 0;
        int time = 0;
        int duration = 0;
        stream >> name >> sizeInBytes >> time >> duration >> status;

        Task* task = new Task(name, sizeInBytes, time, duration);
        task->setStatus(status);
        return task;
    }
};

