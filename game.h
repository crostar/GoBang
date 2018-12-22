#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>
#include "board.h"

const int WINDOW_HEIGHT = 1000;
const int WINDOW_WIDTH = 1100;

class Game: public QGraphicsView
{
public:
    Game(QGraphicsView* parent = nullptr);
    void start();
    bool isWin(int x, int y, int clr);
    void drawPiece(int x, int y, int clr);
    void endGame();
    void mousePressEvent(QMouseEvent* ev);
private:
    QGraphicsScene* scene;
    Board* board;
    int currentPlayer;

};

#endif // GAME_H
