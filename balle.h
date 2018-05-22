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

    dessiner(); //Dessine la balle
    update(); //Met à jour la position de la balle en fonction de sa position antérieure et du vecteur direction
    float returnPosX(); //Retourne la position x de la balle
    float returnPosY(); //Retourne la position y de la balle
    changeDirectionX(); //Inverse de le sens de x dans le vecteur direction
    changeDirectionY(); //Inverse de le sens de y dans le vecteur direction
    changeDirectionCurseur(float pos); //Met à jour le vecteur direction en fonction du point d'immpact sur le curseur
    void setPosition (float x, float y);
private:

    float position_[2]; //Position de la balle en x et y
    float direction_[2]={0.0f,2.0f}; //Vecteur direction de la balle
    GLUquadric* quad;
    GLdouble radius = 8;//rayon de la sphere
    GLint slices=100; //nombre de cotés que comporte la sphere
    GLint stacks=100; //nombre de rayon composant la sphere

};

#endif // BALLE_H
