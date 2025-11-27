// -----------------------------------------
// Mustafa's Module (Train Movement + Logic)
// -----------------------------------------
#include <iostream>
#include "hammad_track.cpp"
using namespace std;

class TrainSystem {
public:
    Track t;

    TrainSystem(int size) {
        t.createTrack(size);
    }

    bool moveTrain(int id) {
        Node* temp = t.head;
        Node* prev = NULL;

        while (temp != NULL) {
            if (temp->trainID == id) {

                if (temp->next == NULL) {
                    cout << "Train " << id << " reached end of track.\n";
                    return false;
                }

                if (temp->next->trainID != -1) {
                    cout << "❌ Collision detected! Train " << id << " hit Train "
                         << temp->next->trainID << " at position "
                         << temp->next->position << endl;
                    return false;
                }

                temp->trainID = -1;
                temp->next->trainID = id;
                return true;
            }
            prev = temp;
            temp = temp->next;
        }
        return false;
    }

    void simulate(int steps) {
        cout << "\nSimulation Started...\n";
        t.displayTrack();

        for (int i = 1; i <= steps; i++) {
            cout << "\nStep " << i << ":\n";
            moveTrain(1);
            moveTrain(2);
            t.displayTrack();
        }
    }
};

// ----------------------
// Main for demonstration
// ----------------------
int main() {
    TrainSystem sys(10);

    sys.t.placeTrain(2, 1);
    sys.t.placeTrain(4, 2);

    sys.simulate(10);
    return 0;
}
