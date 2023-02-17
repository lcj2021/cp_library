#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "basic.hpp"
#include "ds/segtree/segtree.hpp"
#include "alg/monoid/min.hpp"

void solve() {
    int n, q;   cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a)   cin >> x;
    using monoid = Monoid_Min<int>;
    SegTree<monoid> seg(a);

    while (q --) {
        int l, r;   cin >> l >> r;  // 查询[l, r)
        cout << seg.prod(l, r) << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt -- ) solve();
    return 0;
}