#include "heap.h"

int main() {
    Heap h;
    h.push(10);
    h.push(20);
    h.push(5);

    cout << "Размер: " << h.size() << "\n";
    cout << "Извлекаем: " << h.pop() << "\n";
    cout << "Извлекаем: " << h.pop() << "\n";
    cout << "Извлекаем: " << h.pop() << "\n";

    try {
        h.pop();
    } catch (const char* msg) {
        cout << "Исключение: " << msg << "\n";
    }

    return 0;
}