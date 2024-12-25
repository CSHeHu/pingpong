#ifndef BALL_H
#define BALL_H
#include <QPainter>

class Ball
{
public:
    Ball(float x, float y, float radius, float speed);
    void draw(QPainter &painter) const;
    QRectF getRect() const;
    void moveLeft();
    void moveRight();

private:
    float x, y, radius, speed;
};

#endif // BALL_H
