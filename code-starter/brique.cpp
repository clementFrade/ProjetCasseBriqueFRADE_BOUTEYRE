#include "brique.h"
#include <QApplication>
#include <QDesktopWidget>
    // Declarations des constantes

brique::brique(float x,float y,int life)
{
    x_=x;
    y_=y;
    life_=life;
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

brique::casser()
{
    life_=life_-1;
    if (life_==0){
        delete this;
    }
}

float brique::posx()
{
return x_;
}
float brique::posy()
{
return y_;
}
int brique::life()
{
return life_;
}
