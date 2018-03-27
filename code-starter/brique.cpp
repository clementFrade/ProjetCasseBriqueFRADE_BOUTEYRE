#include "brique.h"
#include <QApplication>
#include <QDesktopWidget>
    // Declarations des constantes

brique::brique(float x,float y)
{
    x_=x;
    y_=y;
}
brique::dessiner()
{
    glBegin(GL_QUADS); // Primitive à afficher et début de la déclaration des vertices de cette primitive
    glVertex2f(x_, y_-40);  // Définition des coordonnées des sommets (en 2D, z=0)
    glVertex2f(x_+120, y_-40);
    glVertex2f(x_+120, y_);
    glVertex2f(x_,y_);
    glEnd();
}
