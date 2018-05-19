#ifndef BRIQUE_H
#define BRIQUE_H
#include <QGLWidget>
#include <QKeyEvent>
#include <QColor>
#include <QVector2D>
#include <GL/glu.h>

class brique
{
public:
    brique(float,float,int);
    dessiner();
    casser();
    float posx();
    float posy();
    int life();
private:
    float x_;
    float y_;
    int life_;
    QImage brique_;
    GLuint textureBrique;
};

#endif // BRIQUE_H
