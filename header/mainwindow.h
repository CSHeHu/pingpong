#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include "paddle.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    Ui::MainWindow *ui;
    Paddle *leftPaddle;
    Paddle *rightPaddle;
    QTimer *timer;
    bool leftUp = false;
    bool leftDown = false;
    bool rightUp = false;
    bool rightDown = false;

private slots:
    void updateGame();

};
#endif // MAINWINDOW_H
