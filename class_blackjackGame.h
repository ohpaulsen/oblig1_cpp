#ifndef CLASS_BLACKJACKGAME_H
#define CLASS_BLACKJACKGAME_H


#include "class_game.h"

namespace casino{
  
  class blackjackGame : public game 
  {
    
    //Overridden from game
    virtual void playRound();
    
  public:
    
    //Constructor
    blackjackGame(int players=1);

    //Overridden from game
    virtual void start();
    
  };

}

#endif
