#include "drawingscene.h"
#include <QDateTime>
#include <QGraphicsItem>

void DrawingScene::setDrawColor() {
    drawColor = QColorDialog::getColor(drawColor, nullptr, "Выберите цвет", QColorDialog::DontUseNativeDialog);
}

void DrawingScene::setDrawWidth() {
    bool ok;
    widthPen = QInputDialog::getDouble(nullptr, "Выберите размер кисти", "Введите размер кисти:", 1.0, 0.1, 100.0, 1, &ok);

    if (!ok) {
        widthPen = 1.0f;
    }
}
void DrawingScene::setDrawMethod(int method)
{
    drawMethod = method;
    setSelectLine(false);
}

void DrawingScene::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape)
    {
        if (currentLine)
        {
            removeItem(currentLine);
            delete currentLine;
            currentLine = nullptr;
        }
    }
}

void DrawingScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (currentLine)
    {
        if (drawMethod == 1)
        {
            currentLine->setLine(QLineF(currentLine->line().p1(), event->scenePos()));
            lines.append(currentLine);
            currentLine = nullptr;
            addLineToList(lines.last());
        }
    }

    else if (selectedLine) {
        QPen pen = selectedLine->pen();
        pen.setColor(currentColor);

        selectedLine->setPen(pen);
        selectedLine = nullptr;
        QApplication::setOverrideCursor(Qt::OpenHandCursor);

    }
}

void DrawingScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (selectedLine)
    {
        QPointF newPos = event->scenePos() - selectedLine->line().p1();
        selectedLine->setLine(QLineF(selectedLine->line().p1() + newPos, selectedLine->line().p2() + newPos));
        QApplication::setOverrideCursor(Qt::ClosedHandCursor);

    }

    else if (currentLine)
    {
        if (drawMethod == 1)
            currentLine->setLine(QLineF(currentLine->line().p1(), event->scenePos()));
    }
}

void DrawingScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        if (isSelectLine)
        {

            QGraphicsItem* item = nullptr;
            QList<QGraphicsItem*> allItems = items();

            for (QGraphicsItem* i : allItems)
            {
                if (i->type() == QGraphicsLineItem::Type && i->boundingRect().contains(event->scenePos()))
                {
                    item = i;
                    break;
                }
            }

            if (item)
            {
                item->setFlag(QGraphicsItem::ItemIsMovable);
                selectedLine = dynamic_cast<QGraphicsLineItem*>(item);


                currentColor = selectedLine->pen().color();
                currentWidth = selectedLine->pen().widthF();

                QPen pen = selectedLine->pen();
                pen.setColor(QColor(Qt::gray));

                selectedLine->setPen(pen);
            }
        }

        else if (drawMethod == 0)
        {
            if (!currentLine)
            {
                currentLine = new QGraphicsLineItem;

                QPen pen = currentLine->pen();

                pen.setColor(drawColor);
                pen.setWidthF(widthPen);
                currentLine->setPen(pen);
                addItem(currentLine);
                isFirstMethodIsClick = true;
                currentLine->setLine(QLineF(event->scenePos(), event->scenePos()));
            }
            else if (isFirstMethodIsClick)
            {
                currentLine->setLine(QLineF(currentLine->line().p1(), event->scenePos()));
                isFirstMethodIsClick = false;
                lines.append(currentLine);

                currentLine = nullptr;

                addLineToList(lines.last());

            }
        }
        else if (drawMethod == 1)
        {
            if (!currentLine)
            {

                currentLine = new QGraphicsLineItem;
                QPen pen = currentLine->pen();
                pen.setColor(drawColor);
                pen.setWidthF(widthPen);

                currentLine->setPen(pen);
                currentLine->setLine(QLineF(event->scenePos(), event->scenePos()));
                addItem(currentLine);

            }
            else
            {
                currentLine->setLine(QLineF(currentLine->line().p1(), event->scenePos()));
            }
        }
    }
}

void DrawingScene::updateLinePosition()
{
    if (drawMethod == 0 && currentLine)
    {
        QPointF cursorPos = views().first()->mapToScene(views().first()->mapFromGlobal(QCursor::pos()));
        currentLine->setLine(QLineF(currentLine->line().p1(), cursorPos));
    }
}

void DrawingScene::drawBackground(QPainter *painter, const QRectF &rect)
{
    Q_UNUSED(rect);
    painter->setBackgroundMode(Qt::OpaqueMode);
    painter->setBackground(QBrush(Qt::white));
}

void DrawingScene::addLineToList(QGraphicsLineItem *line)
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString timeString = currentDateTime.toString("hh:mm:ss");

    int lineNumber = listLines.count()+1;

    QString listItemText = timeString + " - Line " + QString::number(lineNumber);

    QListWidgetItem *listItem = new QListWidgetItem(listItemText);
    listWidget->addItem(listItem);

    lines.append(line);

    ListLines listlines;
    listlines.line = line;
    listlines.listItem = listItem;

    listLines.append(listlines);
}

void DrawingScene::setListWidget(QListWidget* listWidget) {
    this->listWidget = listWidget;
}

void DrawingScene::removeObjectFromList(QListWidgetItem *item)
{
    for (int i = 0; i < listLines.size(); ++i) {
        if (listLines[i].listItem == item) {
            QGraphicsLineItem* line = listLines[i].line;
            QListWidgetItem* item = listLines[i].listItem;

            removeItem(line);
            listWidget->removeItemWidget(item);

            delete line;
            delete item;
        }
    }
}

void DrawingScene::removeAllLines() {
    for (int i = 0; i < listLines.size(); ++i) {
        if (listLines[i].line && listLines[i].listItem) {

            QGraphicsLineItem* line = listLines[i].line;
            QListWidgetItem* item = listLines[i].listItem;

            removeItem(line);
            listWidget->removeItemWidget(item);

            delete line;
            delete item;

            listLines[i].line = nullptr;
            listLines[i].listItem = nullptr;
        }
    }
}

void DrawingScene::setSelectLine(bool isSelected) {
    if (isSelected == false) {
        QApplication::setOverrideCursor(Qt::ArrowCursor);

    }

    else {
        drawMethod = -1;
        QApplication::setOverrideCursor(Qt::OpenHandCursor);
    }

    isSelectLine = isSelected;
}

void DrawingScene::selectLine() {
    setSelectLine(true);
}
