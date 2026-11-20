#include "trie.h"

Node::Node() : is_end(false), count(0) {
    for (int i = 0; i < 26; ++i) children[i] = nullptr;
}

Trie::Trie() : root(new Node()) {}

void Trie::insert(const string& w) {
    if (w.empty()) throw "Empty string";
    Node* c = root;
    for (char x : w) {
        int idx = x - 'a';
        if (c->children[idx] == nullptr)
            c->children[idx] = new Node();
        c = c->children[idx];
    }
    c->is_end = true;
    c->count++;
}

void Trie::dfs(Node* v) {
    if (v->is_end)
        for (int i = 0; i < v->count; ++i)
            a.push_back(cur);
    for (int i = 0; i < 26; ++i) {
        if (v->children[i] != nullptr) {
            cur.push_back('a' + i);
            dfs(v->children[i]);
            cur.pop_back();
        }
    }
}

void Trie::collect(vector<string>& res) {
    a.clear();
    cur.clear();
    dfs(root);
    res = a;
}