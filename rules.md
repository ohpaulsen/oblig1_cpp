C++ BlackJack - House rules.


# Objective
--------------------------------------------
Accumulate cards with point totals as close to 21 without going over 21. 


# Game setup
--------------------------------------------
- 1 to 7 players, plus a dealer


# Card values:
--------------------------------------------
- Face cards are worth 10. 
- Aces are worth 1 or 11, whichever makes a better hand. 
- Other cards are worth their number


# Gameplay:
--------------------------------------------
- Each player, including the dealer,  starts with two cards, one of the dealer's cards is hidden until the end.

## Player actions 

- To 'Hit' is to ask for another card. 
- To 'Stand' is to hold your total and end your turn.

- If you go over 21 you bust, and the dealer wins your money, regardless of the dealer's hand.

- If you "Stand" below 21, the dealers hand is "resolved": 
  -- Dealer must "hit" on anything below 17
  -- Dealer must "stand" on 17 or above
  -- If the dealers hand is 17, but with an ace (soft 17), he must hit.
  -- Dealer never doubles or splits
  
- If you are dealt 21 from the start (Ace & 10), you got a "blackjack".

- "Blackjack" means you win 1.5 the amount of your bet. 

- Dealer will hit until his/her cards total 17 or higher.

- Doubling is like a hit, only the bet is doubled and you only get one more card.

- Split can be done when you have two of the same card - the pair is split into two hands.

- Splitting also doubles the bet, because each new hand is worth the original bet.

- You can only double/split on the first move, or first move of a hand created by a split.

- You cannot play on two aces after they are split.

- You can double on a hand resulting from a split, tripling or quadrupling you bet.

