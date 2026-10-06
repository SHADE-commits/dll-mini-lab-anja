#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* prev;
    Node* next;

    Node(const string& d) : data(d), prev(nullptr), next(nullptr) {}
};

struct List {
    Node* head = nullptr;
    Node* tail = nullptr;
};

// Task 2: Add node to the end
void pushBack(List& L, const string& d) {
    Node* n = new Node(d);

    if (!L.head) {
        L.head = L.tail = n;
        return;
    }

    n->prev = L.tail;
    L.tail->next = n;
    L.tail = n;
}

// Task 3: Forward traversal
void printForward(const List& L) {
    cout << "Forward : ";

    for (Node* p = L.head; p; p = p->next)
        cout << p->data << (p->next ? " <-> " : "");

    cout << "\n";
}

// Task 4: Backward traversal
void printBackward(const List& L) {
    cout << "Backward: ";

    for (Node* p = L.tail; p; p = p->prev)
        cout << p->data << (p->prev ? " <-> " : "");

    cout << "\n";
}

// Task 5: Insert a node after a target node
void insertAfter(List& L, const string& target, const string& d) {
    Node* p = L.head;

    while (p && p->data != target)
        p = p->next;

    if (!p)
        return;

    Node* n = new Node(d);

    n->prev = p;
    n->next = p->next;

    if (p->next)
        p->next->prev = n;
    else
        L.tail = n;

    p->next = n;
}

// Task 6: Delete a node
void deleteNode(List& L, const string& d) {
    Node* p = L.head;

    while (p && p->data != d)
        p = p->next;

    if (!p)
        return;

    if (p->prev)
        p->prev->next = p->next;
    else
        L.head = p->next;

    if (p->next)
        p->next->prev = p->prev;
    else
        L.tail = p->prev;

    delete p;
}

int main() {

    // =========================================
    // TASK 1 & 2: Create and build the list
    // =========================================

    List songs;

    for (string s : {
        "Song A",
        "Song B",
        "Song C",
        "Song D",
        "Song E"
    }) {
        pushBack(songs, s);
    }

    cout << "=== INITIAL LIST ===\n";
    printForward(songs);
    printBackward(songs);


    // =========================================
    // TASK 5: Insert Song X
    // =========================================

    cout << "\n=== AFTER INSERTING SONG X ===\n";

    insertAfter(songs, "Song B", "Song X");

    printForward(songs);
    printBackward(songs);


    // =========================================
    // TASK 6: Delete Song C
    // =========================================

    cout << "\n=== AFTER DELETING SONG C ===\n";

    deleteNode(songs, "Song C");

    printForward(songs);
    printBackward(songs);


    // =========================================
    // TASK 7: Real-world example
    // =========================================

    cout << "\n=== REAL-WORLD EXAMPLE ===\n";
    cout << "Example: Browser History\n";
    cout << "A doubly linked list is suitable because\n";
    cout << "we can move forward and backward between pages.\n";


    // =========================================
    // TASK 8: Prediction
    // =========================================

    cout << "\n=== TASK 8 PREDICTION ===\n";
    cout << "Given: A <-> B <-> C <-> D\n";
    cout << "If C is deleted:\n";
    cout << "Prediction: A <-> B <-> D\n";


    // =========================================
    // TASK 9: Break and Fix
    // =========================================

    cout << "\n=== TASK 9 BREAK AND FIX ===\n";
    cout << "Intentional mistake:\n";
    cout << "Forget to update the prev pointer when deleting a node.\n";
    cout << "Result: backward traversal can still point to the deleted node.\n";
    cout << "Fix: update p->next->prev = p->prev before deleting the node.\n";


    return 0;
}
