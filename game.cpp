#include "game.h"
#include "piece.h"
#include "board.h"
#include <QGraphicsScene>
#include <QMessageBox>
#include <QString>

Game::Game(QGraphicsView *parent): QGraphicsView (parent)
{
    // set view
    setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // set scene
    scene = new QGraphicsScene();
    setScene(scene);
    scene->setSceneRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

    // draw board
    board = new Board();
    scene->addItem(board);
    board->setPos(150, 40);

    // set currentPlayer(by default WHITE)
    currentPlayer = WHITE;

    // start game
    //start();
}

bool Game::isWin(int x, int y, int clr)
{
    int count = 0;
    // verticle
    for (int i = -4; i <= 4; i++)
    {
        if(y+i < COLUMN && y+i >= 0){
            if (board->getState(x, y+i) == clr) count++;
            else count = 0;
            if(count == 5) return true;
        }
    }
    // horizontal
    for (int i = -4; i <= 4; i++)
    {
        if(x+i < COLUMN && x+i >= 0){
            if (board->getState(x+i, y) == clr) count++;
            else count = 0;
            qDebug()<<board->getState(x+i, y)<<clr<<count;
            if(count == 5) return true;
        }
    }
    // left-top to right-bottom
    for (int i = -4; i <= 4; i++)
    {
        if(y+i < COLUMN && y+i >= 0 && x+i < COLUMN && x+i >= 0){
            if (board->getState(x+i, y+i) == clr) count++;
            else count = 0;
            if(count == 5) return true;
        }
    }
    // right-top to left-bottom
    for (int i = -4; i <= 4; i++)
    {
        if(y+i < COLUMN && y+i >= 0 && x-i < COLUMN && x-i >= 0){
            if (board->getState(x-i, y+i) == clr) count++;
            else count = 0;
            if(count == 5) return true;
        }
    }
    return false;
}

void Game::drawPiece(int x, int y, int clr) // parameters x & y represents its column and row number on board
{
    auto piece = new Piece();
    piece->setColor(clr);
    scene->addItem(piece);
    piece->setPos(board->x()+x*GRID_SIZE - PIECE_DIAMETER/2, board->y()+y*GRID_SIZE - PIECE_DIAMETER/2);
}

void Game::endGame()
{
    auto message = new QMessageBox();
    if(currentPlayer == WHITE){
        message->setText("White Win!");
    }
    else if (currentPlayer == BLACK){
        message->setText("Black Win!");
    }
    message->setFixedSize(500, 500);
    message->show();
}

void Game::mousePressEvent(QMouseEvent *ev)
{
    int colNum = static_cast<int>(ev->pos().x() - board->pos().x() + GRID_SIZE/2) / GRID_SIZE;
    int rowNum = static_cast<int>(ev->pos().y() - board->pos().y() + GRID_SIZE/2) / GRID_SIZE;

    // if clicked point in inside the board and ther is no piece on it, draw a piece
    if(colNum >= 0 && colNum <= COLUMN && rowNum>= 0 && rowNum<<COLUMN
            && board->getState(colNum, rowNum) == 0){
        drawPiece(colNum, rowNum, currentPlayer);
        board->setState(colNum, rowNum, currentPlayer);

        // if win, end game
        if(isWin(colNum, rowNum, currentPlayer)){
            endGame();
        }

        //if not, switch turn
        else {
           currentPlayer *= -1;          
        }
    }
}
