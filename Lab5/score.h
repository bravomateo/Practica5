#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>

class Score: public QGraphicsTextItem // Score se hereda QGraphicsTextItem

{
public:

    Score(QGraphicsItem *parent = nullptr); // Constructor para dar valor inicial de 0
    void increase(); // aumentar la puntuación
    int getScore(); // devolver la puntuación

private:
    int score; // puntuacion actual
};

#endif // SCORE_H
