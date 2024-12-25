#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(windowWidth, windowHeigth);
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

void MainWindow::updateGame()
{
    leftPaddle->moveUp();
    update();
}

