#include <iostream>

#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(800, 600);
    leftPaddle = new Paddle(30, 250, 20, 100, 10);
    rightPaddle = new Paddle(750, 250, 20, 100, 10);
    ball = new Ball(400, 300, 15, 3);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateGame);
    timer->start(16);

}

MainWindow::~MainWindow()
{
    delete ui;
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

    update();
}

