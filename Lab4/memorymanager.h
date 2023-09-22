#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H

#include <QVector>

class MemoryManager
{
public:
    MemoryManager(int totalMemorySize);

    // Методы для выделения и освобождения памяти
    int allocateMemory(int taskSize);
    void deallocateMemory(int taskId);
    void clearMemory();
    // Метод для обновления состояния памяти
    QVector<int> getMemoryState() const;

private:
    int totalMemorySize;
    QVector<int> memoryBlocks;
};

#endif // MEMORYMANAGER_H
