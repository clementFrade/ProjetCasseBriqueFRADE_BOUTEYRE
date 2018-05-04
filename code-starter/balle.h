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
    float returnPosX();
    float returnPosY();
    changeDirectionX();
    changeDirectionY();
    changeDirectionCurseur(float pos);
private:

    float position_[2];
    float direction_[2]={1.0f,-1.0f};
    GLUquadric* quad = gluNewQuadric();
    GLdouble radius = 10;//rayon de la sphere
    GLint slices=100;//nombre de cotés que comporte la sphere
    GLint stacks=100;//nombre de rayon composant la sphere
};

#endif // BALLE_H
