#include "class_blackjackStrategy.h"
#include "controlTypes.h"
#include "class_blackjackAction.h"
#include "class_action.h"
#include "controlTypes.h"
using namespace casino;
using namespace std;

blackjackStrategy::blackjackStrategy(controlType e) : strategy::strategy()
{
    //this->t = e;

}

action* blackjackStrategy::takeAction(gameState* g)
{
    action* a = new blackjackAction(controlType(2));
    blackjackAction* action = static_cast<blackjackAction  * > (a);
    //action->getAtype(); 
    return action;
}
