#include "stack.h"

void Stack::push(int val) {
    st.push_back(val);
}

int Stack::pop() {
    if (st.empty()) throw "Stack is empty";
    int v = st.back();
    st.pop_back();
    return v;
}

int Stack::top() {
    if (st.empty()) throw "Stack is empty";
    return st.back();
}

bool Stack::empty() {
    return st.empty();
}

int Stack::size() {
    return st.size();
}