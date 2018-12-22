#include "piece.h"
#include <QDebug>
#include <QBrush>
#include <QColor>


Piece::Piece(QGraphicsEllipseItem *parent): QGraphicsEllipseItem(parent)
{
    // set size
    setRect(0, 0, PIECE_DIAMETER, PIECE_DIAMETER);

    // set color (by default it is white)
    color = WHITE;
}

int Piece::getColor()
{
    return color;
}

void Piece::setColor(int clr)
{
    color = clr;
    if (color == WHITE){
        setBrush(QBrush(QColor(Qt::white)));
    }
    else if (color == BLACK){
        setBrush(QBrush(QColor(Qt::black)));
    }
}
