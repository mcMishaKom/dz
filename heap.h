#pragma once
#include <bits/stdc++.h>
using namespace std;

class Heap {
private:
    vector<int> heap;
    void up(int i);
    void down(int i);
public:
    void push(int k);
    int pop();
    bool empty();
    int size();
};