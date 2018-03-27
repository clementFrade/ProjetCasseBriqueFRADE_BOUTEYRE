#include "balle.h"

balle::balle(float x,float y)
{
    x_=x;
    y_=y;
}
balle::dessiner()
{
    glTranslatef(x_,y_, 0.0);
    gluSphere(quad,radius,slices,stacks);
}
balle::update()
{
    x_+=x_+1;
    y_+=y_+1;
}
