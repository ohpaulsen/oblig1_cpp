#include "class_blackjackAction.h"
#include "controlTypes.h"
#include "class_action.h"
#include "gameTypes.h"
#include <iostream>
#include <string>
using namespace casino;
using namespace std;

blackjackAction::blackjackAction(controlType a) : action::action()
{

}

void blackjackAction::print()
{
    cout << "Press H OR STAND" << endl;
    string myString = "";
    cin >> myString;
    if(myString.compare("STAND") == 0 || myString.compare("S") == 0)
    {
        this->actionType = atype(2);
    }
    else if(myString.compare("HIT") == 0 || myString.compare("H") == 0)
    {
        this->actionType = atype(1);
    }
    else
    {
        cout << "Ugyldig kommando" << endl;
    }

}

blackjackAction::atype blackjackAction::getAtype()
{
    print();
    return actionType;
}


