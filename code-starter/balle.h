#ifndef BALLE_H
#define BALLE_H
#include <QGLWidget>
#include <QKeyEvent>
#include <QColor>
#include <QVector2D>
#include <GL/glu.h>

class balle
{
public:
    balle(float,float);
    dessiner();
    update();
private:
    float x_;
    float y_;
    GLUquadric* quad = gluNewQuadric();
    GLdouble radius = 20;//rayon de la sphere
    GLint slices=100;//nombre de cotés que comporte la sphere
    GLint stacks=100;//nombre de rayon composant la sphere
};

#endif // BALLE_H
