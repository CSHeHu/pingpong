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

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateGame);
    timer->start(16);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete leftPaddle;
    delete rightPaddle;
}

void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);  // Create QPainter to draw on the widget

    // Call the paddle's draw method
    leftPaddle->draw(painter);
    rightPaddle->draw(painter);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->type() == QEvent::KeyPress){
        if (event->key() == Qt::Key_W) {
            leftPaddle->moveUp();
        }
        if (event->key() == Qt::Key_S) {
            leftPaddle->moveDown();
            }
        if (event->key() == Qt::Key_Up) {
            rightPaddle->moveUp();
        }
        if (event->key() == Qt::Key_Down) {
            rightPaddle->moveDown();
        }
    }
}


void MainWindow::updateGame()
{

    update();
}

