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
    //Constructeur
    balle(float,float);

    // Destructeur
    virtual ~balle();

    dessiner();
    update();
    float returnPosX();
    float returnPosY();
    changeDirectionX();
    changeDirectionY();
    changeDirectionCurseur(float pos);
    void setPosition (float x, float y);
private:

    float position_[2];
    float direction_[2]={0.0f,1.0f};
    GLUquadric* quad;
    GLdouble radius = 8;//rayon de la sphere
    GLint slices=100;//nombre de cotés que comporte la sphere
    GLint stacks=100;//nombre de rayon composant la sphere
};

#endif // BALLE_H
