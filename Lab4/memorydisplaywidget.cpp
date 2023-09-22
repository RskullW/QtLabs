// memorydisplaywidget.cpp
#include "memorydisplaywidget.h"
#include <QPainter>

MemoryDisplayWidget::MemoryDisplayWidget(QWidget* parent)
    : QWidget(parent)
{
    setMinimumSize(400, 100);
}

void MemoryDisplayWidget::updateMemory(const QVector<int>& memory)
{
    m_memory = memory;
    update();
}

void MemoryDisplayWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    if (width() <= 0 || m_memory.isEmpty()) {
        return;
    }

    int blockSize = width() / m_memory.size();

    for (int i = 0; i < m_memory.size(); ++i)
    {
        QRect blockRect(i * blockSize, 0, blockSize, height());
        QColor fillColor = m_memory[i] == 0 ? Qt::green : Qt::red;
        painter.fillRect(blockRect, fillColor);
        painter.drawRect(blockRect);
    }
}
