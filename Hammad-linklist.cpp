// -------------------------------
// Hammad's Module (Track + Nodes)
// -------------------------------

#include <iostream>
using namespace std;

// Node representing one block of the track
class Node {
public:
    int position;        // Position on track
    int trainID;         // -1 if empty, otherwise train number
    Node* next;

    Node(int pos) {
        position = pos;
        trainID = -1;    // No train placed yet
        next = NULL;
    }
};

// LinkedList representing the full track
class Track {
public:
    Node* head;

    Track() {
        head = NULL;
    }

    // Create track with N positions
    void createTrack(int n) {
        for (int i = 1; i <= n; i++) {
            insertAtEnd(i);
        }
    }

    // Insert node at end (Hammad's linked list core logic)
    void insertAtEnd(int pos) {
        Node* newNode = new Node(pos);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // Place a train at a specific position
    bool placeTrain(int position, int id) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->position == position) {
                if (temp->trainID == -1) {
                    temp->trainID = id;
                    return true;
                } else {
                    cout << "Position already occupied!\n";
                    return false;
                }
            }
            temp = temp->next;
        }
        return false;
    }

    // Print track status
    void displayTrack() {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->trainID == -1)
                cout << "[ " << temp->position << " : Empty ]  ";
            else
                cout << "[ " << temp->position << " : Train " << temp->trainID << " ]  ";
            temp = temp->next;
        }
        cout << endl;
    }
};
