// ------------------------------------------
// Abuzar's Module (Game + Deal + Compare)
// ------------------------------------------
#include <iostream>
#include "abdullah_cards.cpp"
using namespace std;

class WarGame {
public:
    Deck d;
    vector<Card> p1, p2;

    void dealCards() {
        for (int i = 0; i < d.cards.size(); i++) {
            if (i % 2 == 0)
                p1.push_back(d.cards[i]);
            else
                p2.push_back(d.cards[i]);
        }
    }

    void startGame() {
        dealCards();
        cout << "Game Started!\n";

        int score1 = 0, score2 = 0;

        for (int i = 0; i < 26; i++) {
            cout << "\nRound " << i+1 << ":\n";
            cout << "Player 1: " << p1[i].value << " of " << p1[i].suit << endl;
            cout << "Player 2: " << p2[i].value << " of " << p2[i].suit << endl;

            if (p1[i].strength > p2[i].strength) {
                cout << "Player 1 wins round!\n";
                score1++;
            }
            else if (p2[i].strength > p1[i].strength) {
                cout << "Player 2 wins round!\n";
                score2++;
            }
            else {
                cout << "Tie!\n";
            }
        }

        cout << "\nFinal Score:\nP1 = " << score1 << "\nP2 = " << score2 << endl;

        if (score1 > score2)
            cout << "Player 1 Wins the Game!\n";
        else if (score2 > score1)
            cout << "Player 2 Wins the Game!\n";
        else
            cout << "Game Tied!\n";
    }
};

// -------- Main for testing --------
int main() {
    WarGame w;
    w.startGame();
    return 0;
}
