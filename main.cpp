#include "trie.h"

int main() {
    Trie t;
    t.insert("abc");
    t.insert("ab");
    t.insert("abd");
    t.insert("abc");

    vector<string> res;
    t.collect(res);

    cout << "Слова в боре: ";
    for (const string& s : res)
        cout << s << " ";
    cout << "\n";

    try {
        t.insert("");
    } catch (const char* msg) {
        cout << "Исключение: " << msg << "\n";
    }

    return 0;
}