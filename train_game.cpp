#include <iostream>
using namespace std;

// ========================
// Compartment Node Class
// ========================
class Compartment {
public:
    int comp_id;
    int position;
    Compartment* next;

    Compartment(int ci, int p) {
        comp_id = ci;
        position = p;
        next = nullptr;
    }
};

// ========================
// Train Class
// ========================
class Train {
public:
    Compartment* first = nullptr;
    Compartment* last = nullptr;

    void insert_last(int ci, int p) {
        Compartment* newNode = new Compartment(ci, p);
        if (!first) first = last = newNode;
        else { last->next = newNode; last = newNode; }
        cout << "Compartment Added Successfully!\n";
    }

    void delete_last() {
        if (!first) { cout << "No Compartment Available!\n"; return; }
        if (first == last) { delete last; first = last = nullptr; }
        else {
            Compartment* temp = first;
            while (temp->next != last) temp = temp->next;
            delete last;
            last = temp;
            last->next = nullptr;
        }
        cout << "Compartment Removed Successfully!\n";
    }

    void display_train() {
        if (!first) { cout << "No Compartments Available!\n"; return; }
        Compartment* temp = first;
        cout << "Train Compartments: ";
        while (temp) {
            cout << "[C" << temp->comp_id << ":P" << temp->position << "] -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    int get_length() {
        int count = 0;
        Compartment* temp = first;
        while (temp) { count++; temp = temp->next; }
        return count;
    }

    void move_train(int steps) {
        Compartment* temp = first;
        while (temp) { temp->position += ste
