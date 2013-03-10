#ifndef CLASS_BLACKJACKGAME_H
#define CLASS_BLACKJACKGAME_H

#include "class_game.h"
#include "class_card.h"
#include "class_deck.h"
#include "class_blackjackState.h"
#include "class_gameState.h"
#include "class_gambler.h"
#include "class_blackjackStrategy.h"
#include "class_strategy.h"
using std::vector;
namespace casino{
  
  class blackjackGame : public game 
  {
    vector<cards::card> gamblervector;
    vector<cards::card> dealervector;
    cards::deck play_deck;
    gameState *b;
    //blackjackStrategy bS;
    gambler me;
    float bet;
    int players;
    //Overridden from game
    virtual void playRound();
    
  public:
    
    //Constructor
    blackjackGame(int players=1);

    //Overridden from game
    virtual void start();
    
    //Sum of hand
    int SumOfCards(vector<cards::card> c);
    bool printCardSum();
    void winner();
    void dealStartHand(int players, vector<cards::card>& gambler, vector<cards::card>& dealer, cards::deck& play_deck);
  };

}

#endif
