#include "segmenttree.h"

int main() {
    SegmentTree st;
    vector<int> a = {1, 3, 2, 5, 4};
    st.init(5, a);

    Node res = st.query(1, 5);
    cout << "Максимум на [1, 5]: " << res.val << " на позиции " << res.idx << "\n";

    Node res2 = st.query(2, 4);
    cout << "Максимум на [2, 4]: " << res2.val << " на позиции " << res2.idx << "\n";

    try {
        st.query(1, 10);
    } catch (const char* msg) {
        cout << "Исключение: " << msg << "\n";
    }

    return 0;
}