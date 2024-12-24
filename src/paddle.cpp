#include "paddle.h"

Paddle::Paddle(float x, float y, float width, float heigth, float speed)
    :x(x), y(y), width(width), heigth(heigth), speed(speed)
{

}

void Paddle::draw(QPainter &painter) const
{
    painter.setBrush(Qt::blue);  // Paddle color
    painter.drawRect(QRectF(x, y, width, heigth));
}
