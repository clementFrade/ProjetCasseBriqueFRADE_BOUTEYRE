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

protected:

    // Fonction d'initialisation
    void initializeGL();

    // Fonction de redimensionnement
    void resizeGL(int width, int height);

    // Fonction d'affichage
    void paintGL();

    // Fonction de gestion d'interactions clavier
    void keyPressEvent(QKeyEvent * event);

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
    // Quelques variables a definir
    std::vector<brique *> l_brique;

};

#endif // MYGLWIDGET_H
