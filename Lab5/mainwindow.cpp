#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) // configurar la interfaz de la ventana principal
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    QRect Desktop = QApplication::desktop()->screenGeometry();
    x = Desktop.x();
    y = Desktop.y();
    ancho = Desktop.width();
    alto=Desktop.height();

    // Crear la escena rectangular utilizando con las coordenadas (0,0) como origen y un tamaño de 540x600
    scene = new QGraphicsScene(x,y,ancho,alto);
    scene->setSceneRect(0,0,540,600);
    scene->setBackgroundBrush(QBrush(Qt::black));


    ui->graphicsView->setScene(scene);

    puntaje= new Score();     // crear Puntuacion
    personaje = new sprite(); // crear Pacman

    scene->addItem(personaje);
    personaje->setPos(20,20);
    puntaje->setPos(-150,10);
    scene->addItem(puntaje);

{
    paredes2.append(new paredes(20,220,20,20));
    paredes2.append(new paredes(20,240,20,-360));
    paredes2.append(new paredes(100,20,0,-180));
    paredes2.append(new paredes(20,60,-80,-200));
    paredes2.append(new paredes(100,20,20,-240));
    paredes2.append(new paredes(120,20,20,-300));
    paredes2.append(new paredes(20,60,-80,-320));
    paredes2.append(new paredes(80,20,0,-360));
    paredes2.append(new paredes(20,220,-540,20));
    paredes2.append(new paredes(20,240,-540,-360));
    paredes2.append(new paredes(100,20,-440,-180));
    paredes2.append(new paredes(20,60,-440,-200));
    paredes2.append(new paredes(100,20,-460,-240));
    paredes2.append(new paredes(120,20,-440,-300));
    paredes2.append(new paredes(20,60,-440,-320));
    paredes2.append(new paredes(80,20,-460,-360));
    paredes2.append(new paredes(580,20,20,20));
    paredes2.append(new paredes(580,20,20,-600));
    paredes2.append(new paredes(60,40,-40,-40));
    paredes2.append(new paredes(60,20,-40,-120));
    paredes2.append(new paredes(80,40,-140,-40));
    paredes2.append(new paredes(80,40,-140,-40));
    paredes2.append(new paredes(60,40,-440,-40));
    paredes2.append(new paredes(80,40,-320,-40));
    paredes2.append(new paredes(60,20,-440,-120));
    paredes2.append(new paredes(140,20,-200,-120));
    paredes2.append(new paredes(20,80,-260,-120));
    paredes2.append(new paredes(20,100,-260,20));
    paredes2.append(new paredes(20,140,-140,-120));
    paredes2.append(new paredes(80,20,-140,-180));
    paredes2.append(new paredes(20,140,-380,-120));
    paredes2.append(new paredes(80,20,-320,-180));
    paredes2.append(new paredes(20,80,-140,-300));
    paredes2.append(new paredes(20,80,-380,-300));
    paredes2.append(new paredes(140,20,-200,-360));
    paredes2.append(new paredes(20,80,-260,-360));
    paredes2.append(new paredes(140,20,-200,-480));
    paredes2.append(new paredes(20,60,-260,-500));
    paredes2.append(new paredes(60,20,-40,-420));
    paredes2.append(new paredes(20,60,-80,-440));
    paredes2.append(new paredes(40,20,0,-480));
    paredes2.append(new paredes(180,20,-40,-540));
    paredes2.append(new paredes(20,60,-140,-480));
    paredes2.append(new paredes(80,20,-140,-420));
    paredes2.append(new paredes(60,20,-440,-420));
    paredes2.append(new paredes(20,60,-440,-440));
    paredes2.append(new paredes(40,20,-500,-480));
    paredes2.append(new paredes(180,20,-320,-540));
    paredes2.append(new paredes(20,60,-380,-480));
    paredes2.append(new paredes(80,20,-320,-420));
    paredes2.append(new paredes(50,20,-200,-240));
    paredes2.append(new paredes(50,20,-290,-240));
    paredes2.append(new paredes(140,20,-200,-300));
    paredes2.append(new paredes(20,80,-200,-240));
    paredes2.append(new paredes(20,80,-320,-240));
}

{   monedas.append(new moneda(-35,-35,520,20)); // x y
    monedas.append(new moneda(-35,-35,520,40));
    monedas.append(new moneda(-35,-35,520,60));
    monedas.append(new moneda(-35,-35,520,80));
    monedas.append(new moneda(-35,-35,520,100));
    monedas.append(new moneda(-35,-35,520,120));
    monedas.append(new moneda(-35,-35,520,140));
    monedas.append(new moneda(-35,-35,520,160));


    monedas.append(new moneda(-35,-35,500,160));
    monedas.append(new moneda(-35,-35,480,160));
    monedas.append(new moneda(-35,-35,460,160));
    monedas.append(new moneda(-35,-35,440,160));

    monedas.append(new moneda(-35,-35,500,20));
    monedas.append(new moneda(-35,-35,480,20));
    monedas.append(new moneda(-35,-35,460,20));
    monedas.append(new moneda(-35,-35,440,20));
    monedas.append(new moneda(-35,-35,420,20));
    monedas.append(new moneda(-35,-35,400,20));
    monedas.append(new moneda(-35,-35,380,20));
    monedas.append(new moneda(-35,-35,360,20));
    monedas.append(new moneda(-35,-35,340,20));
    monedas.append(new moneda(-35,-35,320,20));
    monedas.append(new moneda(-35,-35,300,20));

    monedas.append(new moneda(-35,-35,240,20));
    monedas.append(new moneda(-35,-35,220,20));
    monedas.append(new moneda(-35,-35,200,20));
    monedas.append(new moneda(-35,-35,180,20));
    monedas.append(new moneda(-35,-35,160,20));
    monedas.append(new moneda(-35,-35,140,20));
    monedas.append(new moneda(-35,-35,100,20));
    monedas.append(new moneda(-35,-35,80,20));
    monedas.append(new moneda(-35,-35,60,20));

    monedas.append(new moneda(-35,-35,20,60));
    monedas.append(new moneda(-35,-35,20,80));
    monedas.append(new moneda(-35,-35,20,100));
    monedas.append(new moneda(-35,-35,20,120));
    monedas.append(new moneda(-35,-35,20,140));
    monedas.append(new moneda(-35,-35,20,160));

    monedas.append(new moneda(-35,-35,40,160));
    monedas.append(new moneda(-35,-35,60,160));
    monedas.append(new moneda(-35,-35,80,160));
    monedas.append(new moneda(-35,-35,100,160));

    monedas.append(new moneda(-35,-35,40,100));
    monedas.append(new moneda(-35,-35,60,100));
    monedas.append(new moneda(-35,-35,80,100));
    monedas.append(new moneda(-35,-35,100,100));

    monedas.append(new moneda(-35,-35,500,100));
    monedas.append(new moneda(-35,-35,480,100));
    monedas.append(new moneda(-35,-35,460,100));
    monedas.append(new moneda(-35,-35,440,100));

    monedas.append(new moneda(-35,-35,400,100));
    monedas.append(new moneda(-35,-35,380,100));
    monedas.append(new moneda(-35,-35,360,100));
    monedas.append(new moneda(-35,-35,340,100));
    monedas.append(new moneda(-35,-35,320,100));
    monedas.append(new moneda(-35,-35,300,100));
    monedas.append(new moneda(-35,-35,280,100));
    monedas.append(new moneda(-35,-35,260,100));
    monedas.append(new moneda(-35,-35,240,100));
    monedas.append(new moneda(-35,-35,220,100));
    monedas.append(new moneda(-35,-35,200,100));
    monedas.append(new moneda(-35,-35,180,100));
    monedas.append(new moneda(-35,-35,160,100));
    monedas.append(new moneda(-35,-35,140,100));

    monedas.append(new moneda(-35,-35,420,20));
    monedas.append(new moneda(-35,-35,420,40));
    monedas.append(new moneda(-35,-35,420,60));
    monedas.append(new moneda(-35,-35,420,80));
    monedas.append(new moneda(-35,-35,420,100));
    monedas.append(new moneda(-35,-35,420,120));
    monedas.append(new moneda(-35,-35,420,140));
    monedas.append(new moneda(-35,-35,420,160));
    monedas.append(new moneda(-35,-35,420,180));
    monedas.append(new moneda(-35,-35,420,200));
    monedas.append(new moneda(-35,-35,420,220));
    monedas.append(new moneda(-35,-35,420,240));
    monedas.append(new moneda(-35,-35,420,260));
    monedas.append(new moneda(-35,-35,420,280));
    monedas.append(new moneda(-35,-35,420,300));

    monedas.append(new moneda(-35,-35,420,320));
    monedas.append(new moneda(-35,-35,420,340));
    monedas.append(new moneda(-35,-35,420,360));
    monedas.append(new moneda(-35,-35,420,380));
    monedas.append(new moneda(-35,-35,420,400));
    monedas.append(new moneda(-35,-35,420,420));
    monedas.append(new moneda(-35,-35,420,440));
    monedas.append(new moneda(-35,-35,420,460));
    monedas.append(new moneda(-35,-35,420,480));
    monedas.append(new moneda(-35,-35,420,500));
    monedas.append(new moneda(-35,-35,420,520));
    monedas.append(new moneda(-35,-35,420,580));



    monedas.append(new moneda(-35,-35,120,20));
    monedas.append(new moneda(-35,-35,120,40));
    monedas.append(new moneda(-35,-35,120,60));
    monedas.append(new moneda(-35,-35,120,80));
    monedas.append(new moneda(-35,-35,120,100));
    monedas.append(new moneda(-35,-35,120,120));
    monedas.append(new moneda(-35,-35,120,140));
    monedas.append(new moneda(-35,-35,120,160));
    monedas.append(new moneda(-35,-35,120,180));
    monedas.append(new moneda(-35,-35,120,200));
    monedas.append(new moneda(-35,-35,120,220));
    monedas.append(new moneda(-35,-35,120,240));
    monedas.append(new moneda(-35,-35,120,260));
    monedas.append(new moneda(-35,-35,120,280));
    monedas.append(new moneda(-35,-35,120,300));


    monedas.append(new moneda(-35,-35,120,320));
    monedas.append(new moneda(-35,-35,120,340));
    monedas.append(new moneda(-35,-35,120,360));
    monedas.append(new moneda(-35,-35,120,380));
    monedas.append(new moneda(-35,-35,120,400));
    monedas.append(new moneda(-35,-35,120,420));
    monedas.append(new moneda(-35,-35,120,440));
    monedas.append(new moneda(-35,-35,120,460));
    monedas.append(new moneda(-35,-35,120,480));
    monedas.append(new moneda(-35,-35,120,500));
    monedas.append(new moneda(-35,-35,120,520));
    monedas.append(new moneda(-35,-35,120,580));


    monedas.append(new moneda(-35,-35,20,580));
    monedas.append(new moneda(-35,-35,20,560));
    monedas.append(new moneda(-35,-35,20,540));
    monedas.append(new moneda(-35,-35,20,520));

    monedas.append(new moneda(-35,-35,40,580));
    monedas.append(new moneda(-35,-35,60,580));
    monedas.append(new moneda(-35,-35,80,580));
    monedas.append(new moneda(-35,-35,100,580));
    monedas.append(new moneda(-35,-35,140,580));
    monedas.append(new moneda(-35,-35,160,580));
    monedas.append(new moneda(-35,-35,180,580));
    monedas.append(new moneda(-35,-35,200,580));
    monedas.append(new moneda(-35,-35,220,580));
    monedas.append(new moneda(-35,-35,240,580));
    monedas.append(new moneda(-35,-35,260,580));
    monedas.append(new moneda(-35,-35,280,580));
    monedas.append(new moneda(-35,-35,300,580));
    monedas.append(new moneda(-35,-35,320,580));
    monedas.append(new moneda(-35,-35,340,580));
    monedas.append(new moneda(-35,-35,360,580));
    monedas.append(new moneda(-35,-35,380,580));
    monedas.append(new moneda(-35,-35,400,580));
    monedas.append(new moneda(-35,-35,440,580));
    monedas.append(new moneda(-35,-35,460,580));
    monedas.append(new moneda(-35,-35,480,580));
    monedas.append(new moneda(-35,-35,500,580));
    monedas.append(new moneda(-35,-35,520,580));

    monedas.append(new moneda(-35,-35,520,560));
    monedas.append(new moneda(-35,-35,520,540));
    monedas.append(new moneda(-35,-35,520,520));

    monedas.append(new moneda(-35,-35,500,520));
    monedas.append(new moneda(-35,-35,480,520));
    monedas.append(new moneda(-35,-35,460,520));
    monedas.append(new moneda(-35,-35,440,520));

    monedas.append(new moneda(-35,-35,40,520));
    monedas.append(new moneda(-35,-35,60,520));
    monedas.append(new moneda(-35,-35,80,520));
    monedas.append(new moneda(-35,-35,100,520));

}

    for(auto it2=monedas.begin();it2!=monedas.end();it2++){ // mostrar las monedas
        scene->addItem(*it2);
    }

    for(auto it = paredes2.begin(); it != paredes2.end();it++){ // mostrar las paredes
        scene->addItem(*it);
    }
}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    if(evento->key() == Qt::Key_A){ // mover hacia la izquiera
        personaje->left();
        personaje->setRotation(180); // mirar a la izquierda
        qDebug()<<personaje->x();
        if(personaje->x() == -20 && personaje->y() == 280) // si se sale por -20 y 280 regresa a 560 y 280 (salirse por la izquierda)
        {
            personaje->setPosx(560); // mostrar el pacman por la derecha
            personaje->setPosy(280);
        }
        for(auto it=paredes2.begin();it!=paredes2.end();it++) // verificar si hay colision con pared
        {
            if(personaje->collidesWithItem(*it)){
                personaje->right(); // si se mueve hacia izquierda se mueve hacia derecha
            }
        }
        for(int i=0;i<monedas.size();i++)
        {
            if(personaje->collidesWithItem(monedas.at(i))){  // verificar si colisiona con alguna moneda
                scene->removeItem(monedas.at(i)); // eliminar las moneda
                monedas.removeAt(i);
                puntaje->increase(); // aumentar el puntaje
            }
        }
    }

    else if(evento->key() == Qt::Key_D){ // mover hacia la derecha
        personaje->right();
        personaje->setRotation(0); // mirar a la derecha
        //qDebug()<<personaje->x();
        if(personaje->x() == 560 && personaje->y() == 280)  // si se sale por 560 y 280 regresa a -20 y 280 (salirse por la derecha)
        {
            personaje->setPosx(-20); // mostrar el pacman por la izquierda
            personaje->setPosy(280);
        }
        for(auto it=paredes2.begin();it!=paredes2.end();it++) // verificar si hay colision con alguna pared
        {
            if(personaje->collidesWithItem(*it)){
                personaje->left(); // si se mueve hacia derecha se mueve hacia izquierda
            }
        }
        for(int i=0;i<monedas.size();i++)
        {
            if(personaje->collidesWithItem(monedas.at(i))){  // verificar si colisiona con alguna moneda
                scene->removeItem(monedas.at(i));  // eliminar las moneda
                monedas.removeAt(i);
                puntaje->increase();  // aumentar el puntaje
            }
        }       
    }

    else if(evento->key() == Qt::Key_S) // mover hacia arriba

    {
        personaje->up();  // mover sprite hacia arriba
        personaje->setRotation(270); // mirar hacia arriba
        //qDebug()<<personaje->y();
        for(auto it=paredes2.begin();it!=paredes2.end();it++) // verificar si hay colision con alguna pared
        {
            if(personaje->collidesWithItem(*it)){
                personaje->down(); // si se mueve hacia arriba se mueve hacia abajo
            }
        }
        for(int i=0;i<monedas.size();i++)
        {
            if(personaje->collidesWithItem(monedas.at(i))){  // verificar si colisiona con alguna moneda
                scene->removeItem(monedas.at(i)); // eliminar las moneda
                monedas.removeAt(i);
                puntaje->increase(); // aumentar el puntaje
            }
        }
    }

    else if(evento->key() == Qt::Key_Z) // mover hacia abajo
    {
        personaje->down(); // mover sprite hacia abajo
        personaje->setRotation(90); // mirar hacia abajo
        //qDebug()<<personaje->y();
        for(auto it=paredes2.begin();it!=paredes2.end();it++) // verificar si hay colision con alguna pared
        {
            if(personaje->collidesWithItem(*it)){
                personaje->up(); // si se mueve hacia abajo se mueve hacia arriba
            }
        }

        for(int i=0;i<monedas.size();i++)
        {
            if(personaje->collidesWithItem(monedas.at(i))){ // verificar si colisiona con alguna moneda
                scene->removeItem(monedas.at(i)); // eliminar las moneda
                monedas.removeAt(i);
                puntaje->increase(); // aumentar el puntaje
            }
        }
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}

