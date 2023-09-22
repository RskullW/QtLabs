#include "memorymanager.h"

MemoryManager::MemoryManager(int totalMemorySize)
    : totalMemorySize(totalMemorySize)
{
    memoryBlocks.resize(totalMemorySize, 0);
}

int MemoryManager::allocateMemory(int taskSize)
{
    // Ищем подходящее место для выделения памяти
    int startBlock = -1;
    int freeBlocks = 0;

    for (int i = 0; i < totalMemorySize; ++i)
    {
        if (memoryBlocks[i] == 0)
        {
            if (freeBlocks == 0)
            {
                startBlock = i;
            }
            ++freeBlocks;
            if (freeBlocks == taskSize)
            {
                // Нашли подходящее место
                for (int j = startBlock; j < startBlock + taskSize; ++j)
                {
                    memoryBlocks[j] = taskSize;
                }
                return startBlock;
            }
        }
        else
        {
            freeBlocks = 0;
        }
    }

    // Не удалось найти подходящее место
    return -1;
}

void MemoryManager::deallocateMemory(int taskId)
{
    if (taskId < 0 || taskId >= totalMemorySize)
    {
        return; // Недопустимый идентификатор задачи
    }

    int taskSize = memoryBlocks[taskId];
    if (taskSize == 0)
    {
        return; // Этот блок памяти уже был освобожден
    }

    // Освобождаем память, заменяя значения на 0
    for (int i = taskId; i < taskId + taskSize; ++i)
    {
        memoryBlocks[i] = 0;
    }
}

QVector<int> MemoryManager::getMemoryState() const
{
    return memoryBlocks;
}

void MemoryManager::clearMemory() {
    for (int i = 0; i < memoryBlocks.size(); ++i) {
        memoryBlocks[i] = 0;
    }
}
