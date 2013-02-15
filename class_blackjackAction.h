#ifndef CLASS_BLACKJACKACTION_H
#define CLASS_BLACKJACKACTION_H


namespace casino{

  typedef enum{HIT,STAND,SPLIT,DOUBLE} blackJackMove;
  
  class blackjackAction : public action {
    blackJackMove m;    
    
  public:
    blackJackMove move();
  };
  
}

#endif

