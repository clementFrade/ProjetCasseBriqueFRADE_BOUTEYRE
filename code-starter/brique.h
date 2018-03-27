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
    brique(float,float);
    dessiner();
private:
    float x_;
    float y_;
};

#endif // BRIQUE_H
