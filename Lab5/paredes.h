#ifndef PAREDES_H
#define PAREDES_H

#include <QGraphicsItem>
#include <QPainter>

class paredes: public QGraphicsItem
{
// Private:
    int w,h;  // Almacenar el ancho (w) y la altura (h) de la pared
    int posx, posy; // Almacenar las coordenadas x e y de la posición de la pared

public:
    paredes(int w_, int h_, int x, int y); // Constructor recibe ancho w_, altura h_ y las coordenadas x e y de posición de la pared
    QRectF boundingRect() const; // delimitador de la pared en la escena

     // dibujar la pared en la escena usando un objeto QPainter.
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // PAREDES_H
