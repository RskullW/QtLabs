#pragma once
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QInputDialog>
#include <QColorDialog>
#include <QGraphicsSceneMouseEvent>
#include <QMenu>
#include <QPushButton>
#include <QVBoxLayout>
#include <QListWidgetItem>
#include <QTimer>

class DrawingScene : public QGraphicsScene
{
    Q_OBJECT

public:
    DrawingScene() : currentLine(nullptr), selectedLine(nullptr), drawMethod(0), drawColor(Qt::black) {
        followCursorTimer = new QTimer(this);
        connect(followCursorTimer, SIGNAL(timeout()), this, SLOT(updateLinePosition()));
        followCursorTimer->start(16);

    }

    void drawBackground(QPainter *painter, const QRectF &rect) override;
    void setListWidget(QListWidget* listWidget);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    void keyPressEvent(QKeyEvent *event) override;

public slots:
    void selectLine();
    void updateLinePosition();
    void setDrawMethod(int method);
    void setDrawWidth();
    void setDrawColor();

    void removeObjectFromList(QListWidgetItem *item);

    void removeAllLines();

private:
    struct ListLines {
        QGraphicsLineItem* line;
        QListWidgetItem *listItem;
    };

    void addLineToList(QGraphicsLineItem *line);
    void setSelectLine(bool isSelected);

    bool isFirstMethodIsClick = false;
    bool isSelectLine = false;
    int drawMethod;
    float widthPen = 1.0f;
    float currentWidth = 1.0f;

    QGraphicsLineItem *currentLine;
    QGraphicsLineItem* selectedLine;
    QColor drawColor;
    QColor currentColor;
    QListWidget* listWidget;
    QList<ListLines> listLines;
    QList<QGraphicsLineItem *> lines;
    QTimer* followCursorTimer;

};
