#ifndef CURSEURPALETTE_H
#define CURSEURPALETTE_H
#include <QGLWidget>
#include <QKeyEvent>
#include <QColor>
#include <QVector2D>
#include <GL/glu.h>

class curseurPalette
{
public:
    curseurPalette(float);
    dessiner();
    right();
    left();
    float returnPosX();
    void setX(float x) {x_=x_+x;}
private:
    float x_;
};

#endif // CURSEURPALETTE_H
