#ifndef PIECE_H
#define PIECE_H

#include <QGraphicsEllipseItem>

const int BLACK = -1;
const int WHITE = 1;

const int PIECE_DIAMETER = 50;

class Piece : public QGraphicsEllipseItem
{
public:
    Piece(QGraphicsEllipseItem* parent = nullptr);
    int getColor();
    void setColor(int clr);
private:
    int color;

};

#endif // PIECE_H
