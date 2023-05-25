#include "moneda.h"

moneda::moneda(int w_, int h_, int x, int y) // constructor de moneda
{
    // inicializar las variables
    w = w_;
    h = h_;
    posx = x;
    posy = y;

    // crear un objeto QTimer
    timer2 = new QTimer();
    filas = 0;
    columnas = 0;

    pixmap2 = new QPixmap(":/images/Coin.png");

    //dimensiones imagen
    ancho = 70;
    alto = 62;

    // activa el temporizador timer2 con un intervalo de 100 milisegundos.
    timer2->start(100);
    // se conecta la señal timeout del temporizador a la ranura Actualizacion2 de la clase moneda.
    connect(timer2, &QTimer::timeout, this,&moneda::Actualizacion2);
    // establecer la posición inicial de la moneda en la escena
    setPos(posx,posy);
}

QRectF moneda::boundingRect() const
{
    //retornar un objeto QRectF que define el rectángulo que representa el área ocupada por la moneda en la escena

    /*
     Nota: QRectF(x,y,ancho, alto)
    la coordenada X izquierda del rectángulo está desplazada hacia la izquierda a la mitad del ancho de la moneda
    la coordenada Y superior del rectángulo está desplazada hacia arriba a la mitad de la altura de la moneda
    Se establece en ancho total .
    Se establece en altura total .
    */

    return QRectF(-ancho/2,-alto/2,ancho,alto);

}

// Dibujar la moneda en la escena usando un objeto QPainter.
void moneda::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    // drawPixmap() para dibujar una parte de la imagen de la moneda (pixmap2)
    // en la posición especificada por columnas y filas.

    painter->drawPixmap(-ancho/2, -alto/2,*pixmap2,columnas,filas,ancho,alto);

    //setScale() para ajustar la escala de la moneda a 0.32.
    setScale(0.25);
}



void moneda::Actualizacion2() //  se invoca cada vez que se produce una señal de tiempo (timeout) del temporizador
{
    columnas += 70;
    if(columnas >= 420){
        columnas = 0;
    }
    filas += 62;
    if(filas >= 62){
        filas =0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);  // actualización del área de dibujo de la moneda.

}

