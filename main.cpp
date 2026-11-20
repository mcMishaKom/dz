#include "stack.h"

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "top: " << s.top() << "\n";
    cout << "size: " << s.size() << "\n";

    cout << s.pop() << " " << s.pop() << " " << s.pop() << "\n";

    try {
        cout << s.pop() << "\n";
    } catch (const char* msg) {
        cout << msg << "\n";
    }

    return 0;
}