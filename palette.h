#ifndef PALETTE_H
#define PALETTE_H
#include <QGLWidget>
#include <QKeyEvent>
#include <QColor>
#include <QVector2D>
#include <GL/glu.h>

class palette
{
public:
    palette(float);
    dessiner();
private:
    float x_;
};

#endif // PALETTE_H
