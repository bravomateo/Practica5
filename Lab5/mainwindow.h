#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include <QObject>
#include <QTimer>
#include <QPixmap>
#include <QRect>
#include <QDesktopWidget>
#include <QDebug>
#include "paredes.h"
#include "sprite.h"
#include "moneda.h"
#include "score.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QList<paredes *> paredes2;
    QList<moneda *> monedas;
    Score *puntaje;
    sprite *personaje;
    QTimer *timer;
    float x,y,ancho,alto;
    void keyPressEvent(QKeyEvent * evento);
};
#endif // MAINWINDOW_H
