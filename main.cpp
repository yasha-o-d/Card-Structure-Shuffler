//main.cpp
//  Jesse's Third Challenge
//  Created by Yasha Ormut Durbin on 1/4/18.
//  Copyright © 2018 Yasha Ormut Durbin. All rights reserved.

#include <iostream>
using namespace std;

int main() {
    int suitLen = 13;                                               //Number of cards per suit
    int numSuits = 4;                                               //Number of suits
    int totalCards = suitLen*numSuits;                              //Total length of deck
    int faceMin = 11;                                               //Minimum value for J,Q,K
    int i=0;                                                        //Index for assigning struct in fullDeck array of structs, and then indexing in shuffle loop
    int numShuffles = 10;                                           //Number of rounds of shuffling
    string Suits[4] = {"Diamonds", "Clubs", "Hearts", "Spades"};    //Array containing the four suit types
    struct card {int cardNum; bool faceCard; string theSuit;};      //Define structure's structure
    card fullDeck[numSuits*suitLen];                                //Initialize array of structures
    
    
    //cout << "Unshuffled Deck of Cards:" << endl;
    for (int suit = 0; suit < numSuits; suit++){                                    //Increments through the suits
        for (int card = 0; card < suitLen; card++){                                 //Increments through the cards per suit
            fullDeck[i].cardNum = i+1;                                              //Defines current card structure's card number
            fullDeck[i].faceCard = (((card+1) == 1) || ((card+1) >= faceMin));      //Defines current card structure's face/!face card
            fullDeck[i].theSuit = Suits[suit];                                      //Defines current card structure's suit
            //cout << fullDeck[i].cardNum << ", " << fullDeck[i].faceCard << ", " << fullDeck[i].theSuit << endl; //Displays each structure
            i++;                                                                    //Increments index used for fullDeck array of structures
        }
    }
    
    cout << "Shuffled Deck of Cards (" << numShuffles << " Shuffles):" << endl;
    for (int shuffle = 0; shuffle < numShuffles; shuffle++){        //Outer for-loop determines number of rounds of shuffles
        for (int j = 0; j < totalCards; j++){                       //Increments through whole deck and shuffles (not very well)
            i = (rand()%52);                                        //Generates random index to shuffle deck
            card temp = fullDeck[j];                                //Saves card at position j
            fullDeck[j] = fullDeck[i];                              //Replaces card at position j with card at (random) position i
            fullDeck[i] = temp;                                     //Replaces card at (random) position i with card at position j
        }
    }
    
    for (int j = 0; j < totalCards; j++){                           //Display shuffled cards
        cout << fullDeck[j].cardNum << ", " << fullDeck[j].faceCard << ", " << fullDeck[j].theSuit << endl;
    }

    return 0;
}
