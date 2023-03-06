#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I"

#include "base.hpp"
#include "ds/segtree/lazy_segtree.hpp"
#include "alg/acted_monoid/sum_assign.hpp"

void solve() {
    int n, q;   cin >> n >> q;
    using monoid = ActedMonoid_Sum_Assign<int, infty<int>>;
    LazySegTree<monoid> seg(n);
    while (q --) {
        int op, s, t, x; cin >> op;
        if (op == 0) {
            cin >> s >> t >> x;
            seg.apply(s, t + 1, x);
        } else {
            cin >> s >> t;
            cout << seg.prod(s, t + 1) << endl;
        }
        LOG(seg.prod_all(), seg.get_all())
    }
}

signed main() {
    #ifdef Liucj_2022
freopen("sample.in", "r", stdin);	   freopen("sample.out", "w", stdout);
    #endif
    solve();
    return 0;
}