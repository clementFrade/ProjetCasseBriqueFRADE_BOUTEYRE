#include "myglwidget.h"
#include <QApplication>
#include <QDesktopWidget>
#include <iostream>
using namespace std;

// Declarations des constantes
const unsigned int WIN_WIDTH  = 1366;
const unsigned int WIN_HEIGHT = 768;
const float ASPECT_RATIO      = static_cast<float>(WIN_WIDTH) / WIN_HEIGHT;
const float ORTHO_DIM         = 50.0f;
int a=0;
int c=0;
int h=0;
float x_=0.0;
float y_=0.0f;
float red = 0;
float green = 0;
float blue = 255;
bool esc=false;




// Constructeur
MyGLWidget::MyGLWidget(QWidget * parent) : QGLWidget(parent)
{
    // Reglage de la taille/position
    setFixedSize(WIN_WIDTH, WIN_HEIGHT);
    move(QApplication::desktop()->screen()->rect().center() - rect().center());
    // Connexion du timer
        connect(&m_AnimationTimer,  &QTimer::timeout, [&] {
            m_TimeElapsed += 1.0f / 24.0f;
            updateGL();
        });

        m_AnimationTimer.setInterval(10);

}


// Fonction d'initialisation
void MyGLWidget::initializeGL()
{
    glClearColor(0.3, 0.3, 0.3, 0.3); // Couleur à utiliser lorsqu’on va nettoyer la fenetre ( = le fond) (fond gris)
    for(int i=0;i<10;i++){
        for(int j=0;j<4;j++){
            l_brique.push_back(new brique(i*122.0f,j*-50.0f,1));
        }
    }
    balletest= new balle(743.0f,-685.0f);
    palettetest = new curseurPalette(683.0f);
}

void MyGLWidget::setXBarre(float x){
    pas = x;
}


// Fonction de redimensionnement
void MyGLWidget::resizeGL(int width, int height)
{
    // Definition du viewport (zone d'affichage)
    glViewport(0,0,width,height);
    // Definition de la matrice de projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
   // glOrtho(-ORTHO_DIM * ASPECT_RATIO, ORTHO_DIM * ASPECT_RATIO, -ORTHO_DIM, ORTHO_DIM, -2.0f * ORTHO_DIM, 2.0f * ORTHO_DIM);

    glOrtho(0.0f, 1366.0f,-766.0f,0.0f, -2.0f * ORTHO_DIM, 2.0f * ORTHO_DIM);
    // Definition de la matrice de modele
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


// Fonction d'affichage
void MyGLWidget::paintGL()
{

        glClear(GL_COLOR_BUFFER_BIT); // Effacer le buffer de couleur
        glColor3ub(red,green,blue);  // Couleur à utiliser pour dessiner les objets (dans notre cas bleu)
        glLoadIdentity();//on reinitialise les valeurs
        //glTranslatef(x,y,0);
        //glRotatef(angle,0,0,1);

        for(brique *briques:l_brique){
            briques->dessiner();
        }


        palettetest->dessiner();
        positionCurseur_=palettetest->returnPosX();

        if((positionBalle_[1]<(-700)))
        {
            if (nbBoules>0){
                nbBoules=nbBoules-1;
                balletest->setPosition(palettetest->returnPosX()+60.0,-685.0f);
                setStart();
            }
            else
            {
                balletest->setPosition(2000,2000);
                setStart();
             }
        }
        balletest->update();
        balletest->dessiner();
        positionBalle_[0]=balletest->returnPosX();
        if((positionBalle_[0]<4.0) || (positionBalle_[0]>1362.0))
        {
            balletest->changeDirectionX();
        }

        positionBalle_[1]=balletest->returnPosY();
        if(positionBalle_[1]>-5.0)
        {
            balletest->changeDirectionY();
        }

        if (positionBalle_[1]<-685.0){
            if((positionBalle_[0]>positionCurseur_)&&(positionBalle_[0]<positionCurseur_+120))
             {
                balletest->changeDirectionCurseur((positionBalle_[0]-(positionCurseur_+60.0f))/120.0f);
             }
        }
        std::vector<brique *>::iterator it;
        it=l_brique.begin();
        while(it != l_brique.end())
            {
            if((((*it)->posx()+120)>=balletest->returnPosX())&&(((*it)->posx()<=balletest->returnPosX())&&(((*it)->posy()-40)<=balletest->returnPosY()))&&((*it)->posy()>=balletest->returnPosY()))
            {
                if(((*it)->posx()+122>=balletest->returnPosX())&&((*it)->posx()+118<=balletest->returnPosX()))
                {
                    balletest->changeDirectionX();
                }
                if(((*it)->posx()<=(balletest-2)->returnPosX())&&((*it)->posx()>=(balletest+2)->returnPosX()))
                {
                    balletest->changeDirectionX();
                }
                if((((*it)->posy()-42)<=balletest->returnPosY())&&(((*it)->posy()-38)>=balletest->returnPosY()))
                {
                    balletest->changeDirectionY();
                }
                if((((*it)->posy()-2)<=balletest->returnPosY())&&(((*it)->posy()+2)>=balletest->returnPosY()))
                {
                    balletest->changeDirectionY();
                }
                it = l_brique.erase(it);

            }
            it++;
        }


    palettetest->setX(pas);
}


// Fonction de gestion d'interactions clavier
void MyGLWidget::keyPressEvent(QKeyEvent * event)
{
    switch(event->key())
    {
    case Qt::Key_Left:
    {
        palettetest->left();
        break;
    }
    case Qt::Key_Right:
    {
        palettetest->right();
        break;
    }
        /*
    case Qt::Key_Up:
    {
        y=y+1;
        break;
    }
    case Qt::Key_Down:
    {
        y=y-1;
        break;
    }

        // Changement de l'objet a afficher
        case Qt::Key_Space:
        {
        if(a==0){
            a=1;
        } else if (a==1) {
            a=0;
        }
            break;
        }

        // Sortie de l'application
        case Qt::Key_Escape:
        {
        window()->close();
        esc=true;
            break;
        }*/

        // Cas par defaut
        default:
        {
            // Ignorer l'evenement
            event->ignore();
            return;
        }
    }

    // Acceptation de l'evenement et mise a jour de la scene
    event->accept();
    updateGL();
}

int MyGLWidget::etatPartie () {
    return nbBoules;
}
void MyGLWidget::Newboule(){
    balletest= new balle(500.0f,-500.0f);
    palettetest = new curseurPalette(683.0f);
}

void MyGLWidget::setStart(){
    if(m_AnimationTimer.isActive())
    {
        balletest->update();
        balletest->dessiner();
        m_AnimationTimer.stop();
    }
    else
        m_AnimationTimer.start();

}

void MyGLWidget::deplacement(int direction)
{
    if (direction==1){
        palettetest->right();
    }
    else if (direction==2) {
        palettetest->left();
    }

}

