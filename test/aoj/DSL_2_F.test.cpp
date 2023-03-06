#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"

#include "base.hpp"
#include "ds/segtree/lazy_segtree.hpp"
#include "alg/acted_monoid/min_assign.hpp"

void solve() {
    int n, q;   cin >> n >> q;
    using monoid = ActedMonoid_Min_Assign<int, -1>;
    vector<int> raw(n, ((int)1 << 31) - 1);
    LazySegTree<monoid> seg(raw);
    while (q --) {
        int op, s, t, x; cin >> op;
        if (op == 0) {
            cin >> s >> t >> x;
            seg.apply(s, t + 1, x);
        } else {
            cin >> s >> t;
            int ans = seg.prod(s, t + 1);
            cout << ans << endl;
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