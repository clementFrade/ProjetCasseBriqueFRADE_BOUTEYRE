#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <opencv2/opencv.hpp>
#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <QDebug>

#include <cstdio>
#include <iostream>
using namespace cv;
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    cv::VideoCapture webcam;

    QImage imgCamera;

    QTimer* timer_;

    Mat image1,image2,rectangle1,rectangle2;

public:
    void keyPressEvent(QKeyEvent * event);



public slots:
    void update();
};

#endif // MAINWINDOW_H
