#include "task.h"

Task::Task(const QString& name, int sizeInBytes, int maxStartTime, int duration)
    : name_(name), sizeInBytes_(sizeInBytes), maxStartTime_(maxStartTime), duration_(duration)
{
}

QString Task::name() const
{
    return name_;
}

Task::TaskStatus Task::status() const
{
    return status_;
}

int Task::sizeInBytes() const
{
    return sizeInBytes_;
}

int Task::maxStartTime() const
{
    return maxStartTime_;
}

int Task::duration() const
{
    return duration_;
}

int Task::taskId() const {
    return taskId_;
}
