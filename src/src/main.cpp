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

void pushBack(List& L, const string& d) {
    Node* n = new Node(d);
    if (!L.head) { L.head = L.tail = n; return; }
    n->prev = L.tail;
    L.tail->next = n;
    L.tail = n;
}

void printForward(const List& L) {
    cout << "Forward : ";
    for (Node* p = L.head; p; p = p->next)
        cout << p->data << (p->next ? " <-> " : "");
    cout << "\n";
}

void printBackward(const List& L) {
    cout << "Backward: ";
    for (Node* p = L.tail; p; p = p->prev)
        cout << p->data << (p->prev ? " <-> " : "");
    cout << "\n";
}

Node* findNode(const List& L, const string& d) {
    for (Node* p = L.head; p; p = p->next)
        if (p->data == d) return p;
    return nullptr;
}

bool insertAfter(List& L, const string& target, const string& d) {
    Node* q = findNode(L, target);
    if (!q) return false;
    Node* n = new Node(d);
    n->prev = q;
    n->next = q->next;
    if (q->next) q->next->prev = n; else L.tail = n;
    q->next = n;
    return true;
}

bool deleteNode(List& L, const string& d) {
    Node* p = findNode(L, d);
    if (!p) return false;
    if (p->prev) p->prev->next = p->next; else L.head = p->next;
    if (p->next) p->next->prev = p->prev; else L.tail = p->prev;
    delete p;
    return true;
}

int main() {
    List songs;
    for (string s : {"Song A", "Song B", "Song C", "Song D", "Song E"}) pushBack(songs, s);
    printForward(songs);
    printBackward(songs);

    cout << "\nSetelah insert Song X:\n";
    insertAfter(songs, "Song B", "Song X");
    printForward(songs);
    printBackward(songs);

    cout << "\nSetelah hapus Song C:\n";
    deleteNode(songs, "Song C");
    printForward(songs);
    printBackward(songs);
    return 0;
}
