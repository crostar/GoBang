#include "board.h"
#include <QList>
#include <QGraphicsLineItem>



Board::Board(QGraphicsRectItem *parent): QGraphicsRectItem(parent)
{
    // set size
    setRect(0, 0, GRID_SIZE*(COLUMN-1), GRID_SIZE*(COLUMN-1));

    // initialize stateList
    for (int i=0; i<COLUMN*COLUMN; i++){
        stateList << 0;
    }

    // draw lines on board
    QList<QGraphicsLineItem*> lines;
    for (int i=0; i<COLUMN; i++){
        QGraphicsLineItem* lineVerticle = new QGraphicsLineItem(rect().x()+i*GRID_SIZE, rect().y(),
                                                        rect().x()+i*GRID_SIZE, rect().y()+ GRID_SIZE*(COLUMN-1), this);
        QGraphicsLineItem* lineHorizontal = new QGraphicsLineItem(rect().x(), rect().y()+i*GRID_SIZE,
                                                        rect().x()+ GRID_SIZE*(COLUMN-1), rect().y()+i*GRID_SIZE, this);
        lines<<lineVerticle<<lineHorizontal;
    }
}

int Board::getState(int x, int y)
{
    return stateList[x*COLUMN + y];
}

void Board::setState(int x, int y, int clr)
{
    stateList[x*COLUMN + y] = clr;
}


