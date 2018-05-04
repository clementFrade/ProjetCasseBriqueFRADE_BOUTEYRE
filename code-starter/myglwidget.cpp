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
        m_AnimationTimer.start();

}


// Fonction d'initialisation
void MyGLWidget::initializeGL()
{
    glClearColor(0.3, 0.3, 0.3, 0.3); // Couleur à utiliser lorsqu’on va nettoyer la fenetre ( = le fond) (fond gris)
    for(int i=0;i<10;i++){
        for(int j=0;j<8;j++){
    l_brique.push_back(new brique(35+i*130.0f,j*-50.0f,1));
        }
    }
    balletest= new balle(500.0f,-500.0f);
    palettetest = new curseurPalette(683.0f);
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
        glTranslatef(x,y,0);
        glRotatef(angle,0,0,1);

        for(brique *briques:l_brique){
            briques->dessiner();
        }


        palettetest->dessiner();
        balletest->update();
        balletest->dessiner();
        positionBalle_[0]=balletest->returnPosX();
        positionBalle_[1]=balletest->returnPosY();
        positionCurseur_=palettetest->returnPosX();


        if((positionBalle_[0]<0.0) || (positionBalle_[0]>1346.0))
        {
            balletest->changeDirectionX();
        }
        if(positionBalle_[1]>0.0)
        {
            balletest->changeDirectionY();
        }

        if (positionBalle_[1]<-670.0){
            if((positionBalle_[0]>positionCurseur_)&&(positionBalle_[0]<positionCurseur_+120))
             {
                 balletest->changeDirectionY();
             }
        std::vector<brique *>::iterator it;
                it=l_brique.begin();
        while(it != l_brique.end())
            {
        //for(brique *briques:l_brique){
            //cout<<"brique"<<briques->posx()<<"balle"<<balletest->posx()<<"brique"<<briques->posy()<<"balle"<<balletest->posy ()<<endl;
            if((((*it)->posx()+120)>balletest->posx())&&(((*it)->posx()<balletest->posx())&&(((*it)->posy()-40)<balletest->posy()))&&((*it)->posy()>balletest->posy()))
            {
               // cout<<briques->life()<<endl;
                cout<<"touché"<<endl;
                //briques->casser();
                it = l_brique.erase(it) ;
            }
            it++;
        }

}


// Fonction de gestion d'interactions clavier
void MyGLWidget::keyPressEvent(QKeyEvent * event)
{
    switch(event->key())
    {
    /*
        // Changement de couleur du fond
        case Qt::Key_B:
        {
        float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
                float v = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
                float b = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
                float a = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
                glClearColor(r,v,b,a);
            break;
        }

        // Changement de couleur de l'objet
        case Qt::Key_C:
    {
        red = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
               red=red*256;
                green = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
                green=green*256;
                blue = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
                blue=blue*256;
            break;
        }

        // Affichage/Masquage de l'objet
        case Qt::Key_H:
        {
        if(h==0){
            h=1;
        } else if (h==1) {
            h=0;
        }
            break;
        }
    case Qt::Key_X:
    {
        angle=angle+10;
        break;
    }*/
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

