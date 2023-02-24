#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E"

#include "base.hpp"
#include "ds/range_add_range_sum.hpp"

void solve() {
    int n, q;   cin >> n >> q;
    using monoid = Monoid_Add<int>;
    // vector<int> v{1, 2, 3, 4, 5};       // --> {2, 5, 8, 4, 5}
    RangeAddRangeSum<monoid> bit(n);
    // RangeAddRangeSum<monoid> bit(v);
    while (q --) {
        int op, s, t, x; cin >> op;
        if (op == 0) {
            cin >> s >> t >> x;
            s --, t --;
            bit.add(s, t + 1, x);
        } else {
            cin >> x;
            x --;
            cout << bit.sum(x, x + 1) << endl;
        }
    }
}

signed main() {
    solve();
    return 0;
}