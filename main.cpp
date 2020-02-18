#include <fstream>
#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <tuple>
#include "card.hpp"
#include "dealer.hpp"
#include "player.hpp"

using namespace std;

void clrscr(){
    system("cls");
}

void initializeDeck(vector<Card> &d){
    char suits[4] = {'S','H','D','C'};
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            d[13*i+j].setNumber(j+1);
            d[13*i+j].setSuit(suits[i]);
        }
    }
}

/*
bool deal(Player &p1, Dealer &d1){
    bool player = p1.addCard();
    bool dealer = true;
    if(d1.getSum()<18){
        dealer = d1.addCard();
    }
    return (player && dealer);
}
*/
void printDeck(vector<Card> d){
    for(int i=0;i<d.size();i++){
        cout<<d[i].getNumber()<<" ";
    }
    cout<<endl;
}

void printCards(vector<Card> &d){
    for(int i=d.size();i>0;i--){
        int val = rand()%i;
        cout<<i<<" : ";
        d[val].printCard();
        d.erase(d.begin()+val);
        cout<<endl;
    }
    cout<<endl;
}

char compareSum(Player p, Dealer d){
    if(p.getSum()>d.getSum()){
        cout<<p.getName()<<" wins! (Dealer has "<<d.getSum()<<")";
        return 'p';
    }
    else if(d.getSum()>p.getSum()){
        cout<<"Dealer wins! ("<<d.getSum()<<")";
        return 'd';
    }
    else{
        cout<<"Draw!";
        return 'n';
    }
}

bool checkEnd(Player p, Dealer d){
    if(d.getSum()>21 || p.getSum()>21){
        cout<<"\nBust! [Dealer: "<<d.getSum()<<", "<<p.getName()<<": "<<p.getSum()<<"]";
        return true;
    }
    else if(d.getSum()==21 || p.getSum()==21){
        cout<<"\nBlackjack!";
        return true;
    }
    return false;
}

Card deal(vector<Card> &d){
    int val = (rand()%d.size());
    Card t = d[val];
    d.erase(d.begin()+val);
    return t;
}

int startGame(Player &p, Dealer &d, vector<Card> &deck){
    cout << "Bet placed. You now have $" << p.getCash() << endl;
    p.addCard(deal(deck));
    d.addCard(deal(deck));
    p.addCard(deal(deck));
    d.addCard(deal(deck));
    p.printCards();
    cout << p.getSum();
    if(checkEnd(p,d)){
        return 0;
    }
    char choice;
    cout<<"\nHit or Stand? (H/S): ";
    cin>>choice;
    while(choice=='H' || choice=='h'){
        p.addCard(deal(deck));
        p.printCards();
        cout<<p.getSum();
        if (checkEnd(p, d)){
            return 0;
        }
        cout << "\nHit or Stand? (H/S): ";
        cin >> choice;
    }
    return 1;
}

bool dealDealer(Player p, Dealer &d, vector<Card> deck){
    while (d.getSum() < 18){
        d.addCard(deal(deck));
        if (checkEnd(p, d)){
            return false;
        }
    }
    return true;
}

int main(){

    clrscr();
    srand(time(NULL));

    char name[100] = "Inesh";
    vector<Card> deck(52);
    initializeDeck(deck);
    Player player(name);
    Dealer dealer;
    int bet;
    cout<<"Place your bet!\n";
    cout<<player.getName()<<" has $"<<player.getCash()<<"\nBet: ";
    cin>>bet;
    if(player.setBet(bet)){
        if(startGame(player, dealer, deck)==1){
            if(dealDealer(player, dealer, deck)){
                switch(compareSum(player, dealer)){
                    case 'p': player.incrementWins(); break;
                    case 'd':
                    case 'e': break;
                }
            } else{
                //player.incrementWins();
            }
        }
        cout<<"\nYour wins: "<<player.getWins();
    }
    else{
        main();
    }
    /*
    cout << "Hello! What's your name?\n";
    cin>>name;
    Player player(name);
    Dealer dealer;
    clrscr();
    cout<<"Hello "; player.printName();
    while(hit!='N' && hit!='n'){
        status = deal(player, dealer);
        cout<<"\nYou hold: "<<player.getSum();
        cout<<"\nDealer holds: "<<dealer.getSum();
        if(status){
            cout<<"\nHit? ";
            cin>>hit;
        }
        else{
            cout<<"\nGame ended.";
            break;
        }
    }
    if(status){
        if(dealer.getSum()>player.getSum()){
            cout<<"\nDealer wins!";
        }
        else if(dealer.getSum()<player.getSum()){
            cout<<"\nYou win!";
        }
        else{
            cout<<"\nNeutral.";
        }
    }*/
    return 0;
}