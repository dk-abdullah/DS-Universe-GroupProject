// ------------------------------------------
// Abdullah's Module (Deck + Card + Shuffle)
// ------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

class Card {
public:
    string suit;
    string value;
    int strength;

    Card(string s, string v, int str) {
        suit = s;
        value = v;
        strength = str;
    }
};

class Deck {
public:
    vector<Card> cards;

    Deck() {
        createDeck();
        shuffleDeck();
    }

    void createDeck() {
        string suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
        string values[13] =
            {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};

        for (string s : suits) {
            for (int i = 0; i < 13; i++) {
                cards.push_back(Card(s, values[i], i+2));
            }
        }
    }

    void shuffleDeck() {
        random_shuffle(cards.begin(), cards.end());
    }
};
