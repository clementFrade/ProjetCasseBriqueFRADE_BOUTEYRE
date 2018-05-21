#include "curseurpalette.h"

curseurPalette::curseurPalette(float x)
{
    x_=x;
}

curseurPalette::dessiner()
{

    glColor3ub(0,0,0);
    glBegin(GL_QUADS); // Primitive à afficher et début de la déclaration des vertices de cette primitive
    glVertex2f(x_, -700);  // Définition des coordonnées des sommets (en 2D, z=0)
    glVertex2f(x_+120,-700);
    glVertex2f(x_+120,-690);
    glVertex2f(x_,-690);
    glEnd();
}

float curseurPalette::returnPosX()
{
    return x_;
}

curseurPalette::right()
{
    x_=x_+10;

}
curseurPalette::left()
{
    x_=x_-10;
}
void curseurPalette::setX(float pas){
    if(x_>1100.0){
        x_=1100.0;
    }
    else{
        if (x_<0){
            x_=0;
        }
        else {
            x_=x_+pas;
        }

    }

}
