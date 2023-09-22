#ifndef MEMORYDISPLAYWIDGET_H
#define MEMORYDISPLAYWIDGET_H

#include <QWidget>
#include <QVector>

class MemoryDisplayWidget : public QWidget
{
    Q_OBJECT

public:
    MemoryDisplayWidget(QWidget* parent = nullptr);

public slots:
    void updateMemory(const QVector<int>& memory);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    QVector<int> m_memory;
};

#endif // MEMORYDISPLAYWIDGET_H
