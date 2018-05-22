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
    //Constructeur
    brique(float,float,int);
    dessiner(); //Dessine une brique de longueur 120 et hauteur 40 en ajoutant une texture
    float posx() {return x_;} //Retourne la position en x d'une brique
    float posy() {return y_;} //Retourne la position en y d'une brique
    int life() {return life_;} //Retourne le nombre de vie d'une brique
private:
    float x_; //Position en x
    float y_; //Position en y
    int life_; //Nombre de vie
    QImage brique_; //Image utilisé pour la texture
    GLuint textureBrique; //GLuint utilisé pour la texture
};

#endif // BRIQUE_H
