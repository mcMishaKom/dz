#pragma once
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;
public:
    BST();
    void insert(int val);
    bool search(int val) const;
    void remove(int val);
};