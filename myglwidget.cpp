#include "myglwidget.h"
#include <QApplication>
#include <QDesktopWidget>
#include <iostream>
using namespace std;

// Declarations des constantes
const unsigned int WIN_WIDTH  = 1220;
const unsigned int WIN_HEIGHT = 768;
const float ASPECT_RATIO      = static_cast<float>(WIN_WIDTH) / WIN_HEIGHT;
const float ORTHO_DIM         = 50.0f;
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
    for(int i=0;i<11;i++){
        for(int j=0;j<4;j++){
            l_brique.push_back(new brique(i*122.0f,j*-50.0f,1));
        }
    }
    balle_= new balle(743.0f,-685.0f);
    curseur = new curseurPalette(683.0f);
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

    glOrtho(0.0f, 1220.0f,-766.0f,0.0f, -2.0f * ORTHO_DIM, 2.0f * ORTHO_DIM);
    // Definition de la matrice de modele
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


// Fonction d'affichage
void MyGLWidget::paintGL()
{

        glClear(GL_COLOR_BUFFER_BIT); // Effacer le buffer de couleur
        glColor3ub(255,255,255);  // Couleur à utiliser pour dessiner les objets (dans notre cas bleu)
        glLoadIdentity();//on reinitialise les valeurs

        for(brique *briques:l_brique){
            briques->dessiner();
        }


        curseur->dessiner();
        positionCurseur_=curseur->returnPosX();

        if((positionBalle_[1]<(-700)))
        {
            if (nbBoules>1){
                nbBoules=nbBoules-1;
                balle_->setPosition(curseur->returnPosX()+60.0,-685.0f);
                StartStop();
            }
            else
            {
                initializeGL();
                score_=0;
                nbBoules=3;
             }
        }
        balle_->update();
        balle_->dessiner();
        positionBalle_[0]=balle_->returnPosX();
        if((positionBalle_[0]<4.0) || (positionBalle_[0]>1216.0))
        {
            balle_->changeDirectionX();
        }

        positionBalle_[1]=balle_->returnPosY();
        if(positionBalle_[1]>-5.0)
        {
            balle_->changeDirectionY();
        }

        if (positionBalle_[1]<-685.0){
            if((positionBalle_[0]>positionCurseur_)&&(positionBalle_[0]<positionCurseur_+120))
             {
                balle_->changeDirectionCurseur((positionBalle_[0]-(positionCurseur_+60.0f))/120.0f);
             }
        }
        std::vector<brique *>::iterator it;
        it=l_brique.begin();
        while(it != l_brique.end())
            {
            if((((*it)->posx()+120)>=balle_->returnPosX())&&(((*it)->posx()<=balle_->returnPosX())&&(((*it)->posy()-40)<=balle_->returnPosY()))&&((*it)->posy()>=balle_->returnPosY()))
            {
                if(((*it)->posx()+122>=balle_->returnPosX())&&((*it)->posx()+118<=balle_->returnPosX()))
                {
                    balle_->changeDirectionX();
                }
                if(((*it)->posx()<=(balle_-2)->returnPosX())&&((*it)->posx()>=(balle_+2)->returnPosX()))
                {
                    balle_->changeDirectionX();
                }
                if((((*it)->posy()-42)<=balle_->returnPosY())&&(((*it)->posy()-38)>=balle_->returnPosY()))
                {
                    balle_->changeDirectionY();
                }
                if((((*it)->posy()-2)<=balle_->returnPosY())&&(((*it)->posy()+2)>=balle_->returnPosY()))
                {
                    balle_->changeDirectionY();
                }
                it = l_brique.erase(it);
                score_ =score_ + 10;

            }
            it++;
        }


    curseur->setX(pas);
}


// Fonction de gestion d'interactions clavier
void MyGLWidget::keyPressEvent(QKeyEvent * event)
{
    switch(event->key())
    {
    case Qt::Key_Left:
    {
        curseur->left();
        break;
    }
    case Qt::Key_Right:
    {
        curseur->right();
        break;
    }
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

void MyGLWidget::StartStop(){
    if(m_AnimationTimer.isActive())
    {
        balle_->update();
        balle_->dessiner();
        m_AnimationTimer.stop();
    }
    else
        m_AnimationTimer.start();

}

void MyGLWidget::deplacement(int direction)
{
    if (direction==1){
        curseur->right();
    }
    else if (direction==2) {
        curseur->left();
    }

}

