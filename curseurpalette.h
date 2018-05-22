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
    //Constructeur
    curseurPalette(float);
    dessiner(); //Desine le curseur
    right() {x_=x_+10;} //Permet de déplacer le curseur vers la droite
    left()  {x_=x_-10;} //Permet de déplacer le curseur vers la gauche
    float returnPosX() {return x_;} //Retourne position x
    void setX(float pas); //Déplace le curseur en fonction du vecteur de la caméra

private:
    float x_; //Postion du curseur en x
};

#endif // CURSEURPALETTE_H
