#include "sprite.h"
#include "moneda.h"
#include <QDebug>

sprite::sprite(int r_, int x, int y) // constructor de sprite, inicializar radio, posicion en x e y
{
    r = r_;
    posx = x;
    posy = y;
    setPos(posx,posy); // establecer la posicion del sprite en la escena
}
sprite::sprite(QObject *parent) : QObject(parent)
{
    timer = new QTimer(); // inicializar puntero de Qtimer
    pixmap = new QPixmap(":/images/Pacman.png"); // inicializar puntero de QPixmap
    filas = 0;
    columnas = 0;

    //dimensiones imagen
    ancho = 100;
    alto = 100;
    timer->start(100); // definir el timer de 100 ms
    connect(timer,&QTimer::timeout, this,&sprite::Actualizacion); // conectar el slot
    setPos(20,20); // establecer la posición inicial del sprite en la escena

}

void sprite::Actualizacion() // ejecuta cada vez que el QTimer emite la señal de tiempo acabado
{
    columnas += 100; // aumentar 100 para cambiar la posición de la imagen del sprite en la spritesheet.
    if(columnas >= 400){
        columnas = 0; // Si columnas es 400, se reinicia a cero
    }
    this->update(-ancho/2,-alto/2,ancho,alto); //  actualizar la apariencia visual del sprite
}

QRectF sprite::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto); // delimitador del sprite
}


void sprite::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr)
{
    painter->drawPixmap(-ancho/2, -alto/2,*pixmap,columnas,0,ancho,alto);
    setScale(0.35); // dibujar la apariencia visual del sprite utilizando
}

// get y set para acceder y setear  el radio y las posiciones x e y del sprite

int sprite::getR() const
{
    return r;
}

void sprite::setR(int value)
{
    r = value;
}

int sprite::getPosx() const
{
    return posx;
}

void sprite::setPosx(int value)
{
    posx = value;
}

int sprite::getPosy() const
{
    return posy;
}

void sprite::setPosy(int value)
{
    posy = value;
}

// controlar el movimiento del sprite hacia arriba, abajo, izquierda y derecha

void sprite::up()
{
    posy -= 1*velocidad;
    setPos(posx, posy); // Asignar la nueva posicion para subir
}

void sprite::down()
{
    posy += 1*velocidad;
    setPos(posx, posy);  // Asignar la nueva posicion para bajar
}

void sprite::left()
{
    posx -= 1*velocidad;
    setPos(posx, posy);  // Asignar la nueva posicion para izquierda
}

void sprite::right()
{
    posx += 1*velocidad;
    setPos(posx, posy); // Asignar la nueva posicion para derecha
}



