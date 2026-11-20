#include "list.h"

List::List() : head(nullptr), tail(nullptr), sz(0) {}

void List::push_back(int val) {
    Node* n = new Node(val);
    if (!head) {
        head = tail = n;
    } else {
        tail->next = n;
        n->prev = tail;
        tail = n;
    }
    sz++;
}

void List::push_front(int val) {
    Node* n = new Node(val);
    if (!head) {
        head = tail = n;
    } else {
        n->next = head;
        head->prev = n;
        head = n;
    }
    sz++;
}

int List::pop_back() {
    if (!tail) throw "List is empty";
    int v = tail->val;
    Node* p = tail->prev;
    if (p) p->next = nullptr;
    else head = nullptr;
    tail = p;
    sz--;
    return v;
}

int List::pop_front() {
    if (!head) throw "List is empty";
    int v = head->val;
    Node* n = head->next;
    if (n) n->prev = nullptr;
    else tail = nullptr;
    head = n;
    sz--;
    return v;
}

void List::insert(int pos, int val) {
    if (pos < 0 || pos > sz) throw "Invalid position";
    if (pos == 0) { push_front(val); return; }
    if (pos == sz) { push_back(val); return; }
    Node* cur = head;
    for (int i = 0; i < pos; ++i) cur = cur->next;
    Node* n = new Node(val);
    n->prev = cur->prev;
    n->next = cur;
    cur->prev->next = n;
    cur->prev = n;
    sz++;
}

void List::erase(int pos) {
    if (pos < 0 || pos >= sz) throw "Invalid position";
    if (pos == 0) { pop_front(); return; }
    if (pos == sz - 1) { pop_back(); return; }
    Node* cur = head;
    for (int i = 0; i < pos; ++i) cur = cur->next;
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    sz--;
}

void List::print() {
    Node* cur = head;
    while (cur) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << "\n";
}