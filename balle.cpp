#include "balle.h"

balle::balle(float x,float y)
{
    position_[0]=x;
    position_[1]=y;
}

// Destructeur
balle::~balle()
{
    // Destruction des quadriques
    gluDeleteQuadric(quad);
}

balle::dessiner()
{
    glTranslatef(position_[0],position_[1], 0.0);
    glColor3ub(255,0,0);
    gluSphere(quad,radius,slices,stacks);
}
balle::update()
{
    position_[0]=position_[0]+direction_[0];
    position_[1]=position_[1]+direction_[1];
}


float balle::returnPosX()
{
    return position_[0];
}
float balle::returnPosY()
{
    return position_[1];
}

balle::changeDirectionX()
{
    direction_[0]=-direction_[0];
}

balle::changeDirectionY()
{
    direction_[1]=-direction_[1];
}

balle::changeDirectionCurseur(float pos)
{
    direction_[0]=pos;
    direction_[1]=sqrt(1-pos*pos);
    //direction_[0]=-direction_[0]+pos;
    //direction_[1]=-direction_[0]+sin(acos(pos));
}
