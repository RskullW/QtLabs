#pragma once
#include <QGraphicsLineItem>

class MyLineItem : public QGraphicsLineItem
{
public:
    MyLineItem(QGraphicsItem* parent = nullptr);

    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
};
