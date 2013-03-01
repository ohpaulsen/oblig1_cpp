#include "class_game.h"
#include "gameTypes.h"
using namespace casino;

game::game(gameType g, int players)
{
 this->t = g;
    //for (int i = 0; i < players; i++) {
    //add     
 //}
}

gameType game::getType()
{
    return this->t;
}

//i//void game::start()
//{
//virtual game::start();
//}
