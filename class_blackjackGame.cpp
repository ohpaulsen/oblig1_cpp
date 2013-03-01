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
    cout << "Gambler Hand";
    for(int i=0;i < gamblervector.size();i++)
    {
        cout << " "<< this->dealervector[i].name();
    }
    cout << endl;
    cout << "Sum of Gambler Hand " << this->SumOfCards(gamblervector) << endl;
    
    cards::card d = this->dealervector.back();
    cout << endl;
    cout << "Dealers Hand " << d.name() << " And X " << endl;
    cout << "Sum Of Dealer Hand " << endl;
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
    int bilde = 0;
    int under = 0;
    int ess = 0;
    for(vector<card>::size_type it = 0; it != c.size(); it++)
    {
        cout << c[it].getRank() << endl;
        if(!isdigit(ranks[c[it].getRank()]) && ranks[c[it].getRank()] != 'A')
        {
            sum+=10;
            bilde++;
        }
        else if(ranks[c[it].getRank()] == 'A')
        {
          ess++;
        }
        else{
        ////cout << "ranks.. under " << (int)ranks[c[it].getRank] << endl << endl;
        sum += (int)ranks[c[it].getRank()];
        under++;
        }
    }
    cout << "Bilde " << bilde << " under " << under << " ess " << ess << endl;
    return sum;

}
