
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> player1, player2;

    for (int i = 1; i <= 5; i++) {
        player1.push(i);
        player2.push(6 - i);
    }

    while (!player1.empty() && !player2.empty()) {
        int c1 = player1.front(); player1.pop();
        int c2 = player2.front(); player2.pop();
        if (c1 > c2) player1.push(c1 + c2);
        else player2.push(c1 + c2);
    }

    if (player1.empty())
        cout << "Player 2 Wins\n";
    else
        cout << "Player 1 Wins\n";

    return 0;
}
