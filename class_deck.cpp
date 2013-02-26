#include "class_deck.h"
#include "class_card.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>
using namespace cards;
//using namespace std;

deck::deck()
{
//for( int i = 0; i < NUM_RANKS;i++ ){
//    for(int p = 0; p < NUM_SUITS;p++){
//        cards.push_back(card((t_suit)p,(t_rank)i));
//        }
//
deck(1);
//}
}

deck::deck(int deckCount)
{
    for ( int q = 1; q <= deckCount; q++){
        for(int i = 0; i < NUM_RANKS; i ++){
            for(int p =0; p < NUM_SUITS;p++){
                cards.push_back(card((t_suit)p,(t_rank)i));
}}}
}


int myrandom( int i )
{
return std::rand()%i;
}

void deck::shuffle()
{
    srand(time(NULL));
    std::random_shuffle ( cards.begin(), cards.end());
}

card deck::deal()
{
    cards::card c  = this->cards.back();
    this->cards.pop_back();
    return c;
}

int deck::size()
{
    return cards.size();
}
