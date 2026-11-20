#pragma once
#include <bits/stdc++.h>
using namespace std;

class Stack {
private:
    vector<int> st;
public:
    void push(int val);
    int pop();
    int top();
    bool empty();
    int size();
};