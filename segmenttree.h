#pragma once
#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long val;
    int idx;
};

class SegmentTree {
private:
    vector<Node> tree;
    int s;
    int n;
    void recalc(int i);
    void build();
    Node get(int lq, int rq, int i, int l, int r);
public:
    SegmentTree();
    void init(int sz, vector<int> a);
    Node query(int l, int r);
};