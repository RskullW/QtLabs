#ifndef TASK_H
#define TASK_H

#include <QString>

class Task
{
public:
    enum TaskStatus {
        Running,
        Waiting,
        Completed
    };

    Task(const QString& name, int sizeInBytes, int maxStartTime, int duration);

    // Геттеры для атрибутов задачи
    QString name() const;
    TaskStatus status() const;
    int sizeInBytes() const;
    int maxStartTime() const;
    int duration() const;
    int taskId() const;

    void setName(QString value) {name_ = value;}
    void setStatus(TaskStatus value) {status_ = value;}
    void setSizeInBytes(int value) {sizeInBytes_ = value;}
    void setMaxStartTime(int value) {maxStartTime_ = value;}
    void setDuration(int value) {duration_ = value;}
    void setTaskId(int value) {taskId_ = value;}
private:
    QString name_;
    TaskStatus status_;
    int taskId_;
    int sizeInBytes_;
    int maxStartTime_;
    int duration_;
};

#endif // TASK_H
