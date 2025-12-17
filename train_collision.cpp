
#include <iostream>
using namespace std;

struct Compartment {
    int id;
    Compartment* next;
};

Compartment* head = NULL;

void addCompartment(int id) {
    Compartment* temp = new Compartment{id, head};
    head = temp;
}

void deleteCompartment(int id) {
    Compartment* curr = head;
    Compartment* prev = NULL;
    while (curr != NULL && curr->id != id) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) return;
    if (prev == NULL) head = curr->next;
    else prev->next = curr->next;
    delete curr;
}

void displayTrain() {
    Compartment* temp = head;
    while (temp) {
        cout << temp->id << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    addCompartment(1);
    addCompartment(2);
    addCompartment(3);
    displayTrain();
    deleteCompartment(2);
    displayTrain();
    return 0;
}
