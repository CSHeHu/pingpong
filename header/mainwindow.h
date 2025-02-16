#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include "paddle.h"
#include "ball.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private:
    Paddle *leftPaddle;
    Paddle *rightPaddle;
    Ball *ball;
    QTimer *timer;
    bool leftUp = false;
    bool leftDown = false;
    bool rightUp = false;
    bool rightDown = false;
    float windowHeight = 600;
    float windowWidth = 800;

private slots:
    void updateGame();

};
#endif // MAINWINDOW_H
