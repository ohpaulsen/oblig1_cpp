#include "class_blackjackGame.h"
#include "gameTypes.h"
#include "class_game.h"
#include "class_card.h"
#include "class_deck.h"
#include <vector>
#include <iostream>
using namespace std;
using namespace casino;
using namespace cards;

blackjackGame::blackjackGame(int players) : game::game(blackjack,players)
{
    this->players = players; 
    play_deck = cards::deck(2);
}

void blackjackGame::start()
{
    play_deck.shuffle();

    //Giving start hand
    dealStartHand(1, gamblervector, dealervector, play_deck);

    for(i )
    cout << "Gambler Hand " << this->SumOfCards(gamblervector) << endl;
    cards::card d = this->dealervector.back();
    cout << "Dealers Cards " << d.name() << " And X " << endl;
}

void blackjackGame::dealStartHand(int players,vector<card>& gamblervector, vector<card>& dealervector, cards::deck& play_deck)
{
    for(int i=0;i<players;i++)
    {
        for(int p=0;p<2;p++)
        {
            gamblervector.push_back(play_deck.deal());
        }
    }
    dealervector.push_back(play_deck.deal());
    dealervector.push_back(play_deck.deal());
}

void blackjackGame::playRound()
{

}

int blackjackGame::SumOfCards(vector<card> c)
{
    int sum = 0;
    int ess = 0;
    for(vector<card>::size_type it = 0; it != c.size(); it++)
    {
        if(c[it].getRank() > 10)
            sum+=10;
        else if(c[it].getRank() == 1)
        {
          ess++;
        }
        else{
        sum += c[it].getRank();
        }
    }
    if(ess !=0)
    {
        if( ess == 1)
        {
            if(sum > 10)
            {
                sum++;
            }
            else
            {
                sum+=11;
            }
        }
        else if(ess == 2 && c.size() == 2)
        {
            return 12;
        }
        else //Denne tar seg av hvis det er flere enn 2 ess på hånden.. som skjer skjeldent..
        {
            if(sum+ess == 21)
            {
                return 21;
            }
            for(int i=0; i > ess; i--)
            {
                if(sum+11 == 21 )
                {
                    return 21;
                }
            }
        }
    }
    return sum;

}
