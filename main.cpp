#include "stack.h"

int main() {
    Stack s;
    int n, x; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        s.push(x);
    }

    Stack temp;
    while (!s.empty()) {
        int cur = s.pop();
        while (!temp.empty() && temp.top() > cur) {
            s.push(temp.pop());
        }
        temp.push(cur);
    }

    while (!temp.empty()) {
        s.push(temp.pop());
    }

    while (!s.empty()) {
        cout << s.pop() << " ";
    }

    return 0;
}