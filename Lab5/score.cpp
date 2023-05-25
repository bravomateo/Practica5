#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent) // Construcotr de Score
{
    score = 0; // puntuacion en 0
    setPlainText(QString("Score: ")+ QString::number(score)); // Mostrar el texto
    setDefaultTextColor(Qt::white); // Definir el color del texto
    setFont(QFont("Comic Sans MS",14)); // Definir tipo de letra y tamaño
}

void Score::increase() // incrementa la puntuación en 1 cada vez que se llama
{
    score++;  // Aumenta el valor score
    setPlainText(QString("Score: ") + QString::number(score));  // actualiza el texto de la puntuación
}

int Score::getScore()
{
    return score; // devolver el valor actual de la puntuación que existe en score
}
