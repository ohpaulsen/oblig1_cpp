#include "class_blackjackState.h"
#include "class_gameState.h"
#include <vector>
#include <iostream>
using namespace std;
using namespace casino;

blackjackState::blackjackState(vector<vector<cards::card> > cardv, int iHero, int iDealer) : gameState::gameState()
{
  this->cardsDealt = cardv;  
  this->ourHero = iHero;
  this->dealer = iDealer;;
}

void blackjackState::print()
{
   cout << endl;
   cout << "Gambler Hand";
   vector<cards::card> gv = myCards();
   for(int i=0;i < gv.size();i++)
   {
        cout << " " << gv[i].name();
   }
   cout << endl;

}

vector<cards::card> blackjackState::dealersCards()
{
    return cardsDealt[dealer];
}

vector<cards::card> blackjackState::myCards()
{
    return cardsDealt[ourHero];
}

vector<cards::card> blackjackState::cardsI(int i)
{
    return cardsDealt[i];
}

int blackjackState::getOurHero()
{
    return this->ourHero;
}

int blackjackState::getDealer()
{
    return this->dealer;
}
