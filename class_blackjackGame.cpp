#include "class_blackjackGame.h"
#include "gameTypes.h"
#include "class_blackjackState.h"
#include "class_game.h"
#include "class_card.h"
#include "class_deck.h"
#include "class_blackjackStrategy.h"
#include "class_gameState.h"
#include "class_blackjackAction.h"
#include "class_action.h"
#include "controlTypes.h"
#include "gameTypes.h"
#include <vector>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;
using namespace casino;
using namespace cards;

blackjackGame::blackjackGame(int players) : game::game(blackjack,players)
{
    this->players = players; 
    play_deck = cards::deck(2);
    me = gambler("ole","henrik");
    cout << "How much cash do you have.. ?" << endl;
    string myString;
    cin >> myString;
    cash value = ::atof(myString.c_str());
    me.giveMoney(value);
}

void blackjackGame::start()
{
    cout << endl;
    cout << "NEW GAME OF BLACKJACK " << endl;
    cout << endl;
    this->bet = me.placeBet();
    if(play_deck.size() > 7){
        play_deck = cards::deck(2);
    }
    play_deck.shuffle();

    //Giving start hand
    dealStartHand(1, gamblervector, dealervector, play_deck);

    //Dealers hand
    cards::card d = this->dealervector.back();
    cout << "Dealers Hand " << d.name() << " And X " << endl;
    playRound();
}

void blackjackGame::dealStartHand(int players,vector<card>& gamblervector, vector<card>& dealervector, cards::deck& play_deck)
{
    gamblervector.clear();
    dealervector.clear();
    for(int i=0;i<players;i++){
        for(int p=0;p<2;p++){
            gamblervector.push_back(play_deck.deal());
        }
    }
    dealervector.push_back(play_deck.deal());
    dealervector.push_back(play_deck.deal());
}


bool blackjackGame::printCardSum()
{
    cout << "Sum of Gambler Hand " << this->SumOfCards(gamblervector) << endl;
    if(this->SumOfCards(gamblervector) == 21 && gamblervector.size() == 2){
        cout << "BLACKJACK" << endl;
        bet = bet*2,5;
        me.giveMoney(bet);
        return false;
    } if(this->SumOfCards(gamblervector) > 21 ){
        cout << "BURST" << endl;
        return false;
    }
    cout << endl;
    return true;
}
 
void blackjackGame::playRound()
{
    cout << endl;
    vector<vector<cards::card> > cardv;
    cardv.push_back(dealervector);
    cardv.push_back(gamblervector);
    gameState* g = new blackjackState(cardv,1,0);
    g->print();
    blackjackStrategy* bS = new blackjackStrategy(controlType(2));
    if(printCardSum()){
        action* a = bS->takeAction(g);
        blackjackAction * action = static_cast<blackjackAction *> (a);
        blackjackAction::atype temp = action->getAtype();
        if(temp == blackjackAction::atype(2)){
            winner();
            start();
            return;
        }if(temp == blackjackAction::atype(1)){
            this->gamblervector.push_back(play_deck.deal());
            delete g;
            delete a;
            delete bS;
            playRound();
        }else{
           delete a;
           delete bS;
           playRound();
        }
    }else{
        delete g;
        start();
    }
}

void blackjackGame::winner()
{
    dealerPlay();
    if(this->SumOfCards(dealervector) > 21){
        cout << "Dealer busted.. Gambler wins.." << endl;
        me.giveMoney(bet*2);
        return;
    }
    cout << "Gambler have " << this->SumOfCards(gamblervector) << endl;
    cout << "Dealer have " << this->SumOfCards(dealervector) << endl;
        if(this->SumOfCards(gamblervector) > this->SumOfCards(dealervector)){
            me.giveMoney(bet*2);
            cout << "Gambler wins.." << endl;
        }else if(this->SumOfCards(gamblervector) == this->SumOfCards(dealervector)){
            cout << "DRAW..." << endl;
            me.giveMoney(bet);
        }else
            cout << "Dealer wins.." << endl;
}

void blackjackGame::dealerPlay()
{
    int i = 0;
    int temp = this->SumOfCards(dealervector);
    while((this->SumOfCards(dealervector) < 17) || (this->SumOfCards(dealervector) < this->SumOfCards(gamblervector))){
        this->dealervector.push_back(play_deck.deal());
        cout << i << endl;
    }
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
