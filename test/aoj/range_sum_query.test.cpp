#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include "basic.hpp"
#include "ds/fenwicktree/fenwicktree.hpp"

void solve() {
    int n, q;   cin >> n >> q;
    using monoid = Monoid_Add<int>;
    FenwickTree<monoid> bit(n);
    while (q --) {
        int op, x, y; cin >> op >> x >> y;
        if (op == 0) {
            bit.multiply(x - 1, y);
        } else {
            cout << bit.prod(x - 1, y - 1 + 1) << endl;
        }
    }
}

signed main() {
    solve();
    return 0;
}