#include "ball.h"

Ball::Ball(float x, float y, float radius, float speed)
    : x(x), y(y), radius(radius), speed(speed)
{

}

void Ball::draw(QPainter &painter) const
{
   painter.setBrush((Qt::red));
   painter.drawRect(getRect());
}

QRectF Ball::getRect() const
{
    return QRectF(x,y,radius,radius);
}

void Ball::moveLeft()
{

}

void Ball::moveRight()
{

}
