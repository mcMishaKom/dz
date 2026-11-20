#pragma once
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    bool is_end;
    int count;
    Node* children[26];
    Node();
};

class Trie {
private:
    Node* root;
    vector<string> a;
    string cur;
    void dfs(Node* v);
public:
    Trie();
    void insert(const string& w);
    void collect(vector<string>& res);
};