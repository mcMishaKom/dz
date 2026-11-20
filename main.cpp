#include "heap.h"

int main() {
    int n; cin >> n;
    Heap h;
    for (int i = 0; i < n; ++i) {
        int w; cin >> w;
        h.push(w);
    }

    while (h.size() > 1) {
        int y = h.pop();
        int x = h.pop();
        if (x != y) {
            h.push(y - x);
        }
    }

    if (h.empty()) cout << 0 << "\n";
    else cout << h.pop() << "\n";

    return 0;
}