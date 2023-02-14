#pragma once
#include "alg/monoid/add.hpp"

template <typename Monoid>
struct FenwickTree {
    using G = Monoid;
    using E = typename G::value_type;
    int n;
    vector<E> dat;
    E total;
    
    FenwickTree() {}
    FenwickTree(int n) { build(n); }
    template <typename F>
    FenwickTree(int n, F f) {
        build(n, f);
    }
    FenwickTree(const vector<E>& v) { build(v); }

    void build(int m) {
        n = m;
        dat.assign(m, G::unit());
        total = G::unit();
    }
    void build(const vector<E>& v) {
        build(len(v), [&](int i) -> E { return v[i]; } );
    }
    template <typename F>
    void build(int m, F f) {
        n = m;
        dat.clear();
        dat.reserve(m);
        total = G::unit();
        for (int i = 0; i < n; ++ i) { dat.eb(f(i)); }
        for (int i = 1; i <= n; ++ i) {
            int j = i + (i & -i);
            if (j <= n) dat[j - 1] = G::op(dat[j - 1], dat[i - 1]);
        }
        total = prefix_prod(m);
    }

    E prod_all() { return total; }
    E prod(int k) { return prefix_prod(k); }
    E prefix_prod(int k) {
        k = min(k, n);
        E ret = G::unit();
        for (; k > 0; k -= (k & -k)) ret = G::op(ret, dat[k - 1]);
        return ret;
    }
    E prod(int l, int r) {  // [l, r)
        l = max(l, (int)0), r = min(r, n);
        if (l == 0) return prefix_prod(r);
        assert(0 <= l && l <= r && r <= n);
        E pos = G::unit(), neg = G::unit();   // positive, negative
        while (l < r) { pos = G::op(pos, dat[r - 1]), r -= (r & -r); }
        while (r < l) { neg = G::op(neg, dat[l - 1]), l -= (l & -l); }
        return G::op(pos, G::inverse(neg));
    }

    void multiply(int k, E x) {
        static_assert(G::commute);
        total = G::op(total, x);
        for (++ k; k <= n; k += (k & -k)) dat[k - 1] = G::op(dat[k - 1], x);
    }
};
