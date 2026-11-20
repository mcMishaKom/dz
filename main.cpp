#include "bst.h"

int main() {
    BST tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);

    cout << "Поиск 3: " << (tree.search(3) ? "Найден" : "Не найден") << "\n";
    cout << "Поиск 10: " << (tree.search(10) ? "Найден" : "Не найден") << "\n";

    tree.remove(3);
    cout << "После удаления 3, поиск 3: " << (tree.search(3) ? "Найден" : "Не найден") << "\n";

    try {
        tree.remove(100);
    } catch (const char* msg) {
        cout << "Исключение: " << msg << "\n";
    }

    return 0;
}