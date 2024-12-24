#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    leftPaddle = new Paddle(30, 250, 20, 100, 10);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete leftPaddle;
}

void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);  // Create QPainter to draw on the widget

    // Call the paddle's draw method
    leftPaddle->draw(painter);
}
