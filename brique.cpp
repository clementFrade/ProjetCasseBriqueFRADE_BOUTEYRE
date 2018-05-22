#include "brique.h"
#include <QApplication>
#include <QDesktopWidget>


brique::brique(float x,float y,int life)
{
    x_=x;
    y_=y;
    life_=life;
    // Active les textures 2D
    glEnable(GL_TEXTURE_2D);
    // Convertit une image en un format attendu par les fonctions d’OpenGL
    brique_ = QGLWidget::convertToGLFormat(QImage(":/res/brique.jpg"));
    glGenTextures( 1, &textureBrique);     // Crée un objet texture et lui associe un numéro qu’on stocke
    glBindTexture( GL_TEXTURE_2D, textureBrique); // Définit la texture courante
    // Transmet à OpenGL toutes les caractéristiques de la texture courante : largeur, hauteur, format, etc... et bien sûr l'image
    glTexImage2D( GL_TEXTURE_2D, 0, 3, brique_.width(), brique_.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, brique_.bits() );
    // Utilise la méthode GL_LINEAR si besoin pour l’échantillonnage des couleurs
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
}

brique::dessiner()
{
    glBegin(GL_QUADS); // Primitive à afficher et début de la déclaration des vertices de cette primitive
    glTexCoord2f(0, 0); glVertex3f(x_, y_-40, 1);
    glTexCoord2f(1, 0); glVertex3f(x_+120, y_-40, 1);
    glTexCoord2f(1, 1); glVertex3f(x_+120, y_, 1);
    glTexCoord2f(0, 1); glVertex3f(x_,y_, 1);
    glEnd();
}
