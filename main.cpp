#include "list.h"

int main() {
    List l;
    l.push_back(2);
    l.push_back(3);
    l.push_front(1);
    l.print();

    l.insert(1, 9);
    l.print();

    cout << l.pop_front() << " " << l.pop_back() << "\n";

    try {
        l.erase(0);
        while (l.sz > 0)
            cout << l.pop_back() << " ";
        cout << "\n";
        l.pop_back();
    } catch (const char* msg) {
        cout << msg << "\n";
    }

    return 0;
}