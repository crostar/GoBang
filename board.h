#ifndef BOARD_H
#define BOARD_H

#include <QGraphicsRectItem>
#include <QList>

const int GRID_SIZE = 65;
const int COLUMN = 15;

class Board: public QGraphicsRectItem
{
public:
    Board(QGraphicsRectItem* parent = nullptr);
    int getState(int x, int y);
    void setState(int x, int y, int clr);
private:
    QList<int> stateList;
};

#endif // BOARD_H
