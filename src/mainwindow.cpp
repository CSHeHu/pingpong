
#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(windowWidth, windowHeight);
    leftPaddle = new Paddle(30, 250, 20, 100, 10, windowHeight);
    rightPaddle = new Paddle(750, 250, 20, 100, 10, windowHeight);
    ball = new Ball(40, 30, 15, 3, 3, windowWidth, windowHeight);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateGame);
    timer->start(16);

}

MainWindow::~MainWindow()
{
    delete leftPaddle;
    delete rightPaddle;
    delete ball;
}

void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);  // Create QPainter to draw on the widget

    // Call the paddle's draw method
    leftPaddle->draw(painter);
    rightPaddle->draw(painter);
    ball->draw(painter);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_W) leftUp = true;
    if (event->key() == Qt::Key_S) leftDown = true;
    if (event->key() == Qt::Key_Up) rightUp = true;
    if (event->key() == Qt::Key_Down) rightDown = true;
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_W) leftUp = false;
    if (event->key() == Qt::Key_S) leftDown = false;
    if (event->key() == Qt::Key_Up) rightUp = false;
    if (event->key() == Qt::Key_Down) rightDown = false;
}


void MainWindow::updateGame()
{
    if (leftUp) leftPaddle->moveUp();
    if (leftDown) leftPaddle->moveDown();
    if (rightUp) rightPaddle->moveUp();
    if (rightDown) rightPaddle->moveDown();

    ball->move();
    ball->hitWall();
    ball->hitPaddle(*leftPaddle);
    ball->hitPaddle(*rightPaddle);

    update();
}

