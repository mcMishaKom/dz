#include "segmenttree.h"

const long long INF = -10000000000;

SegmentTree::SegmentTree() : s(1), n(0) {}

void SegmentTree::recalc(int i) {
    if (tree[i * 2].val >= tree[i * 2 + 1].val)
        tree[i] = tree[i * 2];
    else
        tree[i] = tree[i * 2 + 1];
}

void SegmentTree::build() {
    for (int i = s - 1; i >= 1; --i) {
        recalc(i);
    }
}

void SegmentTree::init(int sz, vector<int> a) {
    if (sz <= 0) throw "Invalid size";
    n = sz;
    while (s < n) s *= 2;
    tree.resize(2 * s);
    for (int i = 0; i < s; ++i) {
        if (i < n)
            tree[s + i] = {a[i], i + 1};
        else
            tree[s + i] = {INF, -1};
    }
    build();
}

Node SegmentTree::get(int lq, int rq, int i, int l, int r) {
    if (lq <= l && r <= rq) {
        return tree[i];
    }
    if (r <= lq || rq <= l) {
        return {INF, -1};
    }
    int mid = (l + r) / 2;
    Node left = get(lq, rq, i * 2, l, mid);
    Node right = get(lq, rq, i * 2 + 1, mid, r);
    if (left.val >= right.val) return left;
    return right;
}

Node SegmentTree::query(int l, int r) {
    if (l < 1 || r > n || l > r) throw "Invalid range";
    return get(l - 1, r, 1, 0, s);
}