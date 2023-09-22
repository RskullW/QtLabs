#include "mylineitem.h"

MyLineItem::MyLineItem(QGraphicsItem* parent): QGraphicsLineItem(parent) {
    setFlag(QGraphicsItem::ItemIsMovable, true);
}

void MyLineItem::mouseReleaseEvent(QGraphicsSceneMouseEvent* event) {
    setFlag(QGraphicsItem::ItemIsMovable, true);
    QGraphicsLineItem::mouseReleaseEvent(event);
}
