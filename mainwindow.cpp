#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    webcam.open(0);

    if(webcam.isOpened() == false){
        return;
    }

    timer_ = new QTimer(this);
    connect(timer_,SIGNAL(timeout()),this,SLOT(update()));
    timer_->start(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::update(){

    Rect workingRect(120,65,100,100);
    Rect templateRect((workingRect.width-50)/2,(workingRect.height-50)/2,50,50);
    Point workingCenter(workingRect.x+50,workingRect.y+50);

    webcam.set(CV_CAP_PROP_FRAME_WIDTH,320);
    webcam.set(CV_CAP_PROP_FRAME_HEIGHT,240);
    webcam.read(image1);

    cv::flip(image1,image1,1);
    cv::cvtColor(Mat(image1,workingRect),rectangle1,COLOR_BGR2GRAY);

    Mat resultImage;
    int result_cols =  image1.cols- 51;
    int result_rows = image1.rows-50 + 1;
    resultImage.create( result_cols, result_rows, CV_32FC1 );

    // Image2
    webcam.read(image2);
    // Mirror effect
    cv::flip(image2,image2,1);
    cv::cvtColor(Mat(image2,workingRect),rectangle2,COLOR_BGR2GRAY);

    Mat templateImage(rectangle1,templateRect);
    matchTemplate( rectangle2, templateImage, resultImage, TM_CCORR_NORMED );
    // Localisation de la meilleure correspondance
    double minVal; double maxVal; Point minLoc; Point maxLoc;
    minMaxLoc( resultImage, &minVal, &maxVal, &minLoc, &maxLoc);
    // Calcul du vecteur
    Point vect(maxLoc.x-templateRect.x,maxLoc.y-templateRect.y);

    rectangle(image2,workingRect,Scalar( 0, 255, 0),2);
    Point p(workingCenter.x+vect.x,workingCenter.y+vect.y);
    arrowedLine(image2,workingCenter,p,Scalar(255,255,255),2);

        if(vect.x>4){
            ui->JeuCasseBrique->setXBarre((vect.x)/5);
        }
        if(vect.x<-4){
            ui->JeuCasseBrique->setXBarre((vect.x)/5);
        }
        if(vect.y>15){
            ui->JeuCasseBrique->setXBarre(0);
        }
        if(vect.x >10 || vect.x<-10){
            ui->JeuCasseBrique->setXBarre((vect.x)/5);
        }


    QImage imgCamera((uchar*)image2.data,image2.cols,image2.rows,image2.step,QImage::Format_RGB888);
    ui->Camera->setPixmap(QPixmap::fromImage(imgCamera));

    swap(rectangle1,rectangle2);

    ui->NbBalle->setText(QString::number(ui->JeuCasseBrique->boulesDispo()));
    ui->Score->setText(QString::number(ui->JeuCasseBrique->score_));
}


void MainWindow::keyPressEvent(QKeyEvent * event)
{
    switch(event->key())
    {
    case Qt::Key_Space:
    {
        ui->JeuCasseBrique->StartStop();
        break;
    }

    // Sortie de l'application
    case Qt::Key_Escape:
    {
        close();
        break;
    }
    case Qt::Key_Left:
    {
        ui->JeuCasseBrique->deplacement(2);
        break;
    }
    case Qt::Key_Right:
    {
        ui->JeuCasseBrique->deplacement(1);
        break;
    }

    // Cas par defaut
    default:
    {
        // Ignorer l'evenement
        event->ignore();
        return;
    }
  }

    // Acceptation de l'evenement et mise a jour de la scene
    event->accept();

}


