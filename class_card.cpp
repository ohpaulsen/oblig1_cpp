#include "class_card.h"

using namespace cards;
using namespace std;
card::card(t_suit s,t_rank r)
{
 suit = s;
 rank = r;
}

string card::name()
{
    string output = "";
    output += suit_name[rank];
    output += " ";
    output +=ranks[suit];
    return output;
 
}

t_suit card::getSuit()
{
    return suit;
}

t_rank card::getRank()
{
    return rank;
}
