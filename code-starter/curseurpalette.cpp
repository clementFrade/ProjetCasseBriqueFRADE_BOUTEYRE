#include "curseurpalette.h"

curseurPalette::curseurPalette(float x)
{
    x_=x;
}

curseurPalette::dessiner()
{
    glBegin(GL_QUADS); // Primitive à afficher et début de la déclaration des vertices de cette primitive
    glVertex2f(x_, -700);  // Définition des coordonnées des sommets (en 2D, z=0)
    glVertex2f(x_+120,-700);
    glVertex2f(x_+120,-690);
    glVertex2f(x_,-690);
    glEnd();
}
