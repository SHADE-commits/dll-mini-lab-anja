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

int main() {
    List songs;
    for (string s : {"Song A", "Song B", "Song C", "Song D", "Song E"}) pushBack(songs, s);
    printForward(songs);
    return 0;
}
