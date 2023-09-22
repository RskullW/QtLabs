#include "joysticklibrary.h"

JoystickLibrary::JoystickLibrary(QWidget *parent) : QWidget(parent)
{
    circleAngle = 0;
    circleRadius = 0;
    buttonAState = false;
    buttonBState = false;
}

QSize JoystickLibrary::sizeHint() const
{
    return QSize(300, 300);
}

void JoystickLibrary::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Draw outer circle
    painter.setPen(Qt::black);
    painter.drawEllipse(rect().adjusted(10, 10, -10, -10));

    // Draw filled circle at specified angle and radius
    double centerX = width() / 2.0;
    double centerY = height() / 2.0;
    double circleX = centerX + circleRadius * cos(qDegreesToRadians(circleAngle));
    double circleY = centerY - circleRadius * sin(qDegreesToRadians(circleAngle));

    if (buttonAState) {
        painter.setBrush(Qt::blue);
    }

    else {
        painter.setBrush(Qt::green);
    }

    painter.drawEllipse(QPointF(circleX, circleY), 10, 10);

    QLabel *labelA = new QLabel("A", this);
    labelA->setAlignment(Qt::AlignCenter);
    labelA->setGeometry(50, 50, 50, 50);
    labelA->setStyleSheet(buttonAState ? "background-color: green; color: white;" : "background-color: red; color: white;");

    QLabel *labelB = new QLabel("B", this);
    labelB->setAlignment(Qt::AlignCenter);
    labelB->setGeometry(200, 50, 50, 50);
    labelB->setStyleSheet(buttonBState ? "background-color: green; color: white;" : "background-color: red; color: white;");
}

void JoystickLibrary::moveCircle(int angle, int radius, bool buttonAState, bool buttonBState)
{
    circleAngle = angle;
    circleRadius = radius;
    this->buttonAState = buttonAState;
    this->buttonBState = buttonBState;
    update();
}

void JoystickLibrary::resetCirclePosition()
{
    circleAngle = 0;
    circleRadius = 0;
    buttonAState = false;
    buttonBState = false;
    update(); // Redraw the widget
}

QString JoystickLibrary::getCurrentState()
{
    return QString("Angle: %1, Radius: %2, Button A: %3, Button B: %4")
        .arg(circleAngle)
        .arg(circleRadius)
        .arg(buttonAState ? "On" : "Off")
        .arg(buttonBState ? "On" : "Off");
}

void JoystickLibrary::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        resetCirclePosition();
        this->buttonAState = false;
        this->buttonBState = true;
    }

    QWidget::mouseReleaseEvent(event);
}

void JoystickLibrary::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        double centerX = width() / 2.0;
        double centerY = height() / 2.0;
        double deltaX = event->x() - centerX;
        double deltaY = event->y() - centerY;
        double distance = qSqrt(qPow(deltaX, 2) + qPow(deltaY, 2));

        double minRadius = 30;
        double maxRadius = ((width() > height()) ? width() : height()) /2.0 - 20;

        circleRadius = static_cast<int>(minRadius + (maxRadius - minRadius) * (distance / maxRadius)) - 30;

        this->buttonAState = true;
        this->buttonBState = false;
        update();

        double newAngle = qAtan2(-deltaY, deltaX) * 180.0 / M_PI;

        circleAngle = static_cast<int>(newAngle) % 360;
        if (circleAngle < 0) {
            circleAngle += 360;
        }

        if (circleRadius >= maxRadius) {
            circleRadius = width()/2.0-20;
        }

        update(); // Redraw the widget
    }
    QWidget::mouseMoveEvent(event);
}
