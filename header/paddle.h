#ifndef PADDLE_H
#define PADDLE_H
#include <QRectF>
#include <QKeyEvent>
#include <QPainter>

class Paddle
{
public:
    Paddle(float x, float y, float width, float heigth, float speed, float windowHeight);
    void draw(QPainter &painter) const;
    void moveUp();
    void moveDown();
    QRectF getRect() const;
private:
    float x;
    float y;
    float width;
    float heigth;
    float speed;
    float windowHeight;
};

#endif // PADDLE_H
