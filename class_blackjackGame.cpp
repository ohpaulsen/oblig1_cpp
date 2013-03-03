#include "class_blackjackGame.h"
#include "gameTypes.h"
#include "class_blackjackState.h"
#include "class_game.h"
#include "class_card.h"
#include "class_deck.h"
#include "class_gameState.h"
#include <vector>
#include <string>
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
    cout << endl;
    play_deck.shuffle();

    //Giving start hand
    dealStartHand(1, gamblervector, dealervector, play_deck);

    //Dealers hand
    cards::card d = this->dealervector.back();
    cout << "Dealers Hand " << d.name() << " And X " << endl;
    //cout << "Sum Of Dealer Hand " << endl;
    playRound();
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


bool blackjackGame::printCardSum()
{
    cout << "Sum of Gambler Hand " << this->SumOfCards(gamblervector) << endl;
    if(this->SumOfCards(gamblervector) == 21 && gamblervector.size() == 2)
    {
        cout << "BLACKJACK" << endl;
        return false;
    }
    if(this->SumOfCards(gamblervector) > 21 )
    {
        cout << "BURST" << endl;
        return false;
    }
    cout << endl;
    return true;
}
 
void blackjackGame::playRound()
{
    //bool temp = false;
    ///temp = printCardSum();
    vector<vector<cards::card> > cardv;
    cardv.push_back(dealervector);
    cardv.push_back(gamblervector);
    gameState* g = new blackjackState(cardv,1,0);
    g->print();
    if(printCardSum())
    {
        cout << "Press H for Hit And S for Stand" << endl;
        string myString = "";
        cin >> myString;
        if(myString.compare("STAND") == 0)
        {
            winner();
            //start();
            return;
        }else if(myString.compare("HIT") == 0)
        {
            this->gamblervector.push_back(play_deck.deal());
            playRound();
        }else{
            cout << "Ingen gyldig komando" << endl;
        }
    }

}

void blackjackGame::winner()
{
    cout << "Gambler have " << this->SumOfCards(gamblervector) << endl;
    cout << "Dealer have " << this->SumOfCards(dealervector) << endl;
        if(this->SumOfCards(gamblervector) > this->SumOfCards(dealervector) )
            cout << "Gambler wins.." << endl;
        else
            cout << "Dealer wins.." << endl;
}

int blackjackGame::SumOfCards(vector<card> c)
{
    int sum = 0;
    int ess = 0;
    for(vector<card>::size_type i =0; i != c.size(); i++ ){
       if(!isdigit(c[i].getRank()) && c[i].getRank() == 'A'){
            ess++;
        }else if(!isdigit(c[i].getRank())){
           sum+=10;
       }else{
         sum += c[i].getRank() - '0';
       }
    }
    for(int i=0; i < ess; i++){
        int temp = 0;
        if(sum > 10){
            sum++;
            temp++;
        }else{
            sum += 11;
        }
        if(sum > 21 && temp != 0){
            sum-=10;
            temp--;
        }   
    }
    return sum;
}
