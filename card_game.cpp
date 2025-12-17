#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// ========================
// Card Node
// ========================
class Card {
public:
    string no, suit;
    Card* next;
    Card(string n, string s) { no = n; suit = s; next = nullptr; }
};

// ========================
// Deck Class
// ========================
class Deck {
public:
    Card* first = nullptr;
    Card* last = nullptr;

    void create_deck() {
        string suits[4] = {"Heart","Diamond","Club","Spade"};
        for (int s = 0; s < 4; s++) {
            for (int n = 2; n <= 14; n++) {
                string num = (n == 11 ? "J" : n == 12 ? "Q" : n == 13 ? "K" : n == 14 ? "A" : to_string(n));
                Card* newCard = new Card(num, suits[s]);
                if (!first) first = last = newCard;
                else { last->next = newCard; last = newCard; }
            }
        }
    }

    void shuffle() {
        Card* arr[52]; Card* temp = first;
        for (int i = 0; i < 52; i++) { arr[i] = temp; temp = temp->next; }
        for (int i = 51; i > 0; i--) {
            int j = rand() % (i + 1);
            swap(arr[i], arr[j]);
        }
        first = arr[0];
        for (int i = 0; i < 51; i++) arr[i]->next = arr[i + 1];
        arr[51]->next = nullptr;
        last = arr[51];
    }

    Card* deal_card() {
        if (!first) return nullptr;
        Card* dealt = first;
        first = first->next;
        dealt->next = nullptr;
        if (!first) last = nullptr;
        return dealt;
    }
};

// ========================
// Player Class
// ========================
class Player {
public:
    string name;
    Card* hand_first = nullptr;
    Card* hand_last = nullptr;
    int score = 0;

    Player(string n) { name = n; }

    void add_card(Card* c) {
        if (!c) return;
        if (!hand_first) hand_first = hand_last = c;
        else { hand_last->next = c; hand_last = c; }
        c->next = nullptr;
    }

    Card* play_card() {
        if (!hand_first) return nullptr;
        Card* c = hand_first;
        hand_first = hand_first->next;
        c->next = nullptr;
        if (!hand_first) hand_last = nullptr;
        return c;
    }

    int count_cards() {
        int count = 0; Card* temp = hand_first;
        while (temp) { count++; temp = temp->next; }
        return count;
    }

    int get_card_value(Card* c) {
        if (c->no == "A") return 14;
        if (c->no == "K") return 13;
        if (c->no == "Q") return 12;
        if (c->no == "J") return 11;
        return stoi(c->no);
    }
};

// ========================
// Game Class
// ========================
class Game {
public:
    Deck* deck;
    Player* player1;
    Player* player2;
    int level, rounds = 0;

    Game(string p1_name, string p2_name, int lv) {
        deck = new Deck();
        player1 = new Player(p1_name);
        player2 = new Player(p2_name);
        level = lv;
    }

    void initialize_game() {
        deck->create_deck();
        deck->shuffle();
        int i = 0;
        while (deck->first) {
            Card* c = deck->deal_card();
            if (i % 2 == 0) player1->add_card(c);
            else player2->add_card(c);
            i++;
        }
    }

    void play_game() {
        initialize_game();
        while (player1->count_cards() > 0 && player2->count_cards() > 0) {
            rounds++;
            Card* c1 = player1->play_card();
            Card* c2 = player2->play_card();
            int val1 = player1->get_card_value(c1);
            int val2 = player2->get_card_value(c2);

            if (val1 > val2) { player1->score++; player1->add_card(c1); player1->add_card(c2); }
            else { player2->score++; player2->add_card(c1); player2->add_card(c2); }
        }
        cout << "\nGame Over! Scores:\n";
        cout << player1->name << ": " << player1->score << "\n";
        cout << player2->name << ": " << player2->score << "\n";
    }
};

// ========================
// Main Function
// ========================
int main() {
    srand(time(0));
    Game game("Mustafa", "Abdullah", 1);
    game.play_game();
    return 0;
}
