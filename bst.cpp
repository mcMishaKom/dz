#include "bst.h"

BST::BST() : root(nullptr) {}

void BST::insert(int val) {
    if (!root) {
        root = new Node(val);
        return;
    }
    Node* now = root;
    while (true) {
        if (val < now->val) {
            if (!now->left) {
                now->left = new Node(val);
                return;
            }
            now = now->left;
        } else if (val > now->val) {
            if (!now->right) {
                now->right = new Node(val);
                return;
            }
            now = now->right;
        } else {
            return;
        }
    }
}

bool BST::search(int val) const {
    Node* now = root;
    while (now) {
        if (val == now->val) return true;
        if (val < now->val) now = now->left;
        else now = now->right;
    }
    return false;
}

void BST::remove(int val) {
    if (!search(val)) throw "Element not found";
    
    Node* pr = nullptr;
    Node* now = root;
    while (now && now->val != val) {
        pr = now;
        if (val < now->val) now = now->left;
        else now = now->right;
    }
    
    if (!now->left && !now->right) {
        if (now != root) {
            if (pr->left == now) pr->left = nullptr;
            else pr->right = nullptr;
        } else {
            root = nullptr;
        }
        delete now;
    } else if (!now->left) {
        if (now != root) {
            if (pr->left == now) pr->left = now->right;
            else pr->right = now->right;
        } else {
            root = now->right;
        }
        delete now;
    } else if (!now->right) {
        if (now != root) {
            if (pr->left == now) pr->left = now->left;
            else pr->right = now->left;
        } else {
            root = now->left;
        }
        delete now;
    } else {
        Node* okpr = now;
        Node* ok = now->right;
        while (ok->left) {
            okpr = ok;
            ok = ok->left;
        }
        now->val = ok->val;
        if (okpr->left == ok) okpr->left = ok->right;
        else okpr->right = ok->right;
        delete ok;
    }
}