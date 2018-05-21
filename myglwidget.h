#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include "palette.h"
#include <QGLWidget>
#include <QKeyEvent>
#include <QColor>
#include <QVector2D>
#include <QTimer>
#include "brique.h"
#include "balle.h"
#include "curseurpalette.h"


// Classe dediee a l'affichage d'une scene OpenGL
class MyGLWidget : public QGLWidget
{
    Q_OBJECT

public:

    // Constructeur
    MyGLWidget(QWidget * parent = nullptr);
    void setXBarre(float x);
    void setStart();
    int etatPartie ();
    void deplacement (int direction);
    int score_=0;

protected:

    // Fonction d'initialisation
    void initializeGL();

    // Fonction de redimensionnement
    void resizeGL(int width, int height);

    // Fonction d'affichage
    void paintGL();

    // Fonction de gestion d'interactions clavier
    void keyPressEvent(QKeyEvent * event);

    //Fonction de gestion de la partie

    void Newboule();

private:

    QTimer m_AnimationTimer;
    float m_TimeElapsed {1.0f};
    GLfloat x=0;
    GLfloat y=0;
    GLfloat angle=0;
    balle *balletest;
    balle *balletest2;
    curseurPalette *palettetest;
    float positionBalle_[2];
    float positionCurseur_;
    float pas=0.0f;
    std::vector<brique *> l_brique;
    int nbBoules=3;
    bool start;

};

#endif // MYGLWIDGET_H
