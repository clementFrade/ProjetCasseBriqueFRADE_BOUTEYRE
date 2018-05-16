#include "palette.h"

palette::palette(float x)
{
 x_=x;
}

palette::dessiner()
{
    glBegin(GL_QUADS); // Primitive à afficher et début de la déclaration des vertices de cette primitive
    glVertex2f(x_, -380);  // Définition des coordonnées des sommets (en 2D, z=0)
    glVertex2f(x_+120,-380);
    glVertex2f(x_+120, -350);
    glVertex2f(x_,-350);
    glEnd();
}
