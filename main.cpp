#include <QApplication>
#include "game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    auto game = new Game();
    game->show();

    return a.exec();
}


// todo:
//add menu
//add restart
//add mousehover to assist clicking
//add music
//add background image
//make the piece smooth
