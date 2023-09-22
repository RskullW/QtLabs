#ifndef JOYSTICKLIBRARY_H
#define JOYSTICKLIBRARY_H

#include <QWidget>
#include <QLabel>
#include <QPainter>
#include <QMouseEvent>

class JoystickLibrary: public QWidget
{
    Q_OBJECT

public:
    explicit JoystickLibrary(QWidget *parent = nullptr);
    QSize sizeHint() const override;

public slots:
    void moveCircle(int angle, int radius, bool buttonAState, bool buttonBState);
    void resetCirclePosition();
    QString getCurrentState();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    int circleAngle;
    int circleRadius;
    bool buttonAState;
    bool buttonBState;
};


#endif // JOYSTICKLIBRARY_H
