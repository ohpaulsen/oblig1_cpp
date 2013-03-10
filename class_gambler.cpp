#include "class_gambler.h"
#include "class_game.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include <iostream>
#include <string>
using namespace casino;
using namespace std;

gambler::gambler(string fname,string lname)
{
    this->firstName = fname;
    this->lastName = lname;
    this->wallet = 0;
    this->gamblerId = 1; //gamblerNr++;
    this->readyToPlay = true;
}

cash gambler::placeBet()
{
    //this->wallet = 100;
    cout << "You have " << (cash)wallet << "$" << endl;
    cout << "place a bet.." << endl;
    string myString = "";
    cin >> myString;
    cash value = ::atof(myString.c_str());
    if(value > 0 && value <= wallet)
    {
        wallet -= value;
        return value;
    }
    else
    {
        cout << "Du må skrive ett positivt tall og du kan ikke bette mer enn du har." << endl;
        return this->placeBet();
    }
    
}

gambler::gambler(controlType e)
{

}

action* gambler::takeAction(gameState* g)
{

}

void gambler::giveMoney(cash amount)
{
    this->wallet = amount;
}

bool gambler::ready()
{
    return this->readyToPlay;
}


