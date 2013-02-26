#include "class_card.h"
#include <iostream>
using namespace cards;
using namespace std;
card::card(t_suit s,t_rank r)
{
 this->suit = s;
 this->rank = r;
}

string card::name()
{
    return "" + suit_name[this->suit] + " " + ranks[this->rank];
}

t_suit card::getSuit()
{
    return this->suit;
}

t_rank card::getRank()
{
    return this->rank;
}
