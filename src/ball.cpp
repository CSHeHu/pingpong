#include "ball.h"

#include <iostream>

Ball::Ball(float x, float y, float radius, float speedx, float speedy, float windowWidth, float windowHeight)
    : x(x), y(y), radius(radius), speedx(speedx), speedy(speedy), windowWidth(windowWidth), windowHeight(windowHeight)
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

void Ball::move()
{
    x += speedx;
    y += speedy;
}

void Ball::hitPaddle(Paddle &paddle)
{
    if (getRect().intersects(paddle.getRect())){
        speedx = -speedx;
    }


}

void Ball::hitWall()
{
    if (y < 0 || y > windowHeight - radius) {
        speedy = -speedy;
    }

}

