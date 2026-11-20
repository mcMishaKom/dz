#pragma once
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
    Node(int v) : val(v), prev(nullptr), next(nullptr) {}
};

class List {
public:
    Node* head;
    Node* tail;
    int sz;

    List();
    void push_back(int val);
    void push_front(int val);
    int pop_back();
    int pop_front();
    void insert(int pos, int val);
    void erase(int pos);
    void print();
};