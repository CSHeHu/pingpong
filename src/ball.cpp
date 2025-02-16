#include "ball.h"

#include <cstdlib>
#include <iostream>

Ball::Ball(float x, float y, float radius, float speedx, float speedy, float windowWidth, float windowHeight)
: x(x), y(y), radius(radius), speedx(speedx), speedy(speedy), windowWidth(windowWidth), windowHeight(windowHeight)
{
    srand(time(NULL));
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
        speedx = -speedx * 1.02;

        int direction = rand() % 2;  // 0 or 1
        if (direction == 0) {
            direction = -1;  // Move up
        } else {
            direction = 1;  // Move down
        }

        int speed = rand() % 3 + 1;  // Random value between 1 and 3

        speedy = direction * speed;  // Final vertical speed
    }


}

void Ball::hitWall()
{
    if (y < 0 || y > windowHeight - radius) {
        speedy = -speedy;
    }

}

