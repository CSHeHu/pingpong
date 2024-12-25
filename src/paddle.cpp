#include "paddle.h"
#include "mainwindow.h"

Paddle::Paddle(float x, float y, float width, float heigth, float speed)
    :x(x), y(y), width(width), heigth(heigth), speed(speed)
{

}

void Paddle::draw(QPainter &painter) const
{
    painter.setBrush(Qt::blue);  // Paddle color
    painter.drawRect(getRect());
}

void Paddle::moveUp()
{
    if (y>0){
        y -= speed;
    }
}

void Paddle::moveDown()
{
    if (y + heigth < 600){
        y += speed;
    }
}

QRectF Paddle::getRect() const
{
    return QRectF(x, y, width, heigth);
}
