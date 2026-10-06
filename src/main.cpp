#include <iostream>
#include <string>
using namespace std;

// Task 1: Node
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

// Task 2: tambah node di akhir
void pushBack(List& L, const string& d) {
    Node* n = new Node(d);
    if (!L.head) { L.head = L.tail = n; return; }
    n->prev = L.tail;
    L.tail->next = n;
    L.tail = n;
}

Node* findNode(const List& L, const string& d) {
    for (Node* p = L.head; p; p = p->next)
        if (p->data == d) return p;
    return nullptr;
}

// Task 3: jalan maju (pakai next)
void printForward(const List& L) {
    cout << "Forward : ";
    for (Node* p = L.head; p; p = p->next)
        cout << p->data << (p->next ? " <-> " : "");
    cout << "\n";
}

// Task 4: jalan mundur (pakai prev)
void printBackward(const List& L) {
    cout << "Backward: ";
    for (Node* p = L.tail; p; p = p->prev)
        cout << p->data << (p->prev ? " <-> " : "");
    cout << "\n";
}

void printBoth(const List& L) { printForward(L); printBackward(L); }

// Task 5: sisip node setelah node tertentu
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

// Task 6: hapus node (head, tengah, atau tail)
bool deleteNode(List& L, const string& d) {
    Node* p = findNode(L, d);
    if (!p) return false;
    if (p->prev) p->prev->next = p->next; else L.head = p->next;
    if (p->next) p->next->prev = p->prev; else L.tail = p->prev;
    delete p;
    return true;
}

// Task 9: hapus yang SALAH (lupa update prev)
void buggyDelete(List& L, const string& d) {
    Node* p = findNode(L, d);
    if (!p || !p->prev) return;
    p->prev->next = p->next;
    // BUG: lupa  p->next->prev = p->prev;
}

void freeList(List& L) {
    while (L.head) { Node* t = L.head; L.head = t->next; delete t; }
    L.tail = nullptr;
}

int main() {
    cout << "=== Task 2, 3, 4: buat list + jalan dua arah ===\n";
    List songs;
    for (string s : {"Song A", "Song B", "Song C", "Song D", "Song E"}) pushBack(songs, s);
    printBoth(songs);

    cout << "\n=== Task 5: sisip Song X di antara B dan C ===\n";
    insertAfter(songs, "Song B", "Song X");
    printBoth(songs);

    cout << "\n=== Task 6: hapus Song C ===\n";
    deleteNode(songs, "Song C");
    printBoth(songs);
    freeList(songs);

    cout << "\n=== Task 7: contoh dunia nyata (browser history) ===\n";
    List history;
    for (string s : {"google.com", "github.com", "youtube.com", "wikipedia.org"}) pushBack(history, s);
    printBoth(history);
    cout << "Tombol Back pakai prev, tombol Forward pakai next\n";
    freeList(history);

    cout << "\n=== Task 8: prediksi A<->B<->C<->D, hapus C ===\n";
    cout << "Prediksi: A <-> B <-> D (dua arah)\n";
    List t8;
    for (string s : {"A", "B", "C", "D"}) pushBack(t8, s);
    deleteNode(t8, "C");
    printBoth(t8);
    freeList(t8);

    cout << "\n=== Task 9: sengaja salah lalu diperbaiki ===\n";
    List t9;
    for (string s : {"A", "B", "C", "D"}) pushBack(t9, s);
    cout << "-- SALAH (lupa update prev) --\n";
    buggyDelete(t9, "C");
    printBoth(t9);   // backward masih menampilkan C
    freeList(t9);
    cout << "-- BENAR --\n";
    List t9b;
    for (string s : {"A", "B", "C", "D"}) pushBack(t9b, s);
    deleteNode(t9b, "C");
    printBoth(t9b);
    freeList(t9b);
    return 0;
}
