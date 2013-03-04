#include "class_gambler.h"
#include "class_game.h"
#include <string>
using namespace casino;
using namespace std;

gambler::gambler(string fname,string lname)
{
    this->firstName = fname;
    this->lastName = lname;
    this->wallet = 1000;
    this->gamblerId = gamblerNr++;
    this->readyToPlay = true;
}

gambler::gambler(controlType e)
{

}
