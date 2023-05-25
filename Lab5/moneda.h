#ifndef MONEDA_H
#define MONEDA_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class moneda: public QObject, public QGraphicsItem
{
    // private:
    int w,h; // Almacenar el ancho (w) y la altura (h) de la moneda
    int posx, posy; // Almacenar las coordenadas x e y de la posición de la moneda

public:
    moneda(int w_, int h_, int x, int y); // Constructor recibe ancho w_, altura h_ y las coordenadas x e y de posición de la moneda

    //explicit moneda(QObject *parent2 = nullptr);

    QTimer *timer2;  // puntero controlar la actualización de la moneda
    QPixmap *pixmap2; // puntero para pintar la imagen de la moneda
    float filas, columnas, ancho, alto; // disposición de las imágenes en una hoja de sprites

    QRectF boundingRect() const; // delimitador de la moneda en la escena
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr); // dibujar la moneda en la escena usando un objeto QPainter

public slots:

    void Actualizacion2(); // se invoca cuando se produce una actualización de la moneda.

};

#endif // MONEDA_H
