#ifndef BALL_H
#define BALL_H
#include <QPainter>
#include "paddle.h"

class Ball
{
public:
    Ball(float x, float y, float radius, float speedx, float speedy, float windowWidth, float windowHeight);
    void draw(QPainter &painter) const;
    QRectF getRect() const;
    void move();
    void hitPaddle(Paddle &paddle);
    void hitWall();

private:
    float x, y, radius, speedx, speedy, windowWidth, windowHeight;
    bool dirLeft = true;
};

#endif // BALL_H
