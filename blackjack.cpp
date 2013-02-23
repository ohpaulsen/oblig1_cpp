#include <iostream>
#include "class_deck.h"
#include "class_card.h"
//#include "class_deck.cpp"
using namespace std;
//using namespace cards;

int main()
{
    cards::deck k(2); //= cards::deck();
    k.shuffle();
//    cards::card c = k.deal();
//    cards::card d = k.deal();
    cout << k.size() << endl;
    return 0;
}
