#ifndef CLASS_BLACKJACKSTATE_H
#define CLASS_BLACKJACKSTATE_H

#include "class_gameState.h"
namespace casino
{
  class blackjackState : public gameState 
  {
    //Forward declaration
    class card;

    //One vector of cards for each player
    std::vector< std::vector<card> > cardsDealt;
  
    //Location of "my cards" in cardsDealt 
    int ourHero;  
    //Location of dealers cards in cardsDealt
    int dealer;
  
  public:
    void print();
    //Special card getters
    std::vector<card> dealersCards();
    std::vector<card> myCards();
  
    //General card getter
    std::vector<card> cardsI(int i);  
  
    //Special indexes for general card getter
    int getOurHero();
    int getDealer();

  };
}
#endif
