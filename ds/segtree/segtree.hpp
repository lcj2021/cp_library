#pragma once

// ZKW 线段树
template <class Monoid>
struct SegTree {
    using MX = Monoid;
    using X = typename MX::value_type;
    using value_type = X;
    vector<X> dat;
    int n, log, size;

    SegTree() {}
    SegTree(int n) { build(n); }    // [0, n)
    template <typename F>
    SegTree(int n, F f) {
        build(n, f);
    }
    SegTree(const vector<X>& v) { build(v); }

    void build(int m) {
        build(m, [](int i) -> X { return MX::unit(); } );
    }
    void build(const vector<X>& v) {
        build(len(v), [&](int i) -> X { return v[i]; } );
    }
    template <typename F>
    void build(int m, F f) {
        n = m;  log = 1;
        while ((1 << log) < n)  ++ log;
        size = 1 << log;        // 除了叶子节点外的节点总数
        dat.assign(size << 1, MX::unit());
        for (int i = 0; i < n; ++ i) {  // 赋值区间[i, i]
            dat[size + i] = f(i);
        }
        for (int i = size - 1; i >= 1; -- i) {
            update(i);
        }
    }

    X get(int i) { return dat[size + i]; }
    vector<X> get_all() {return {dat.begin() + size, dat.begin() + size + n}; }

    void update(int i) { dat[i] = MX::op(dat[2 * i], dat[2 * i + 1]); }
    void set(int i, const X& x) {
        assert(i < n);
        dat[i += size] = x;
        while (i >>= 1) update(i);
    }

    void multiply(int i, const X& x) {
        assert(i < n);
        i += size;
        dat[i] = MX::op(dat[i], x);
        while (i >>= 1) update(i);
    }

    X prod(int l, int r) {  // 查询区间 [l, r)
        assert(0 <= l && l <= r && r <= n);
        X vl = MX::unit(), vr = MX::unit();
        l += size, r += size;
        while (l < r) {
            if (l & 1)  vl = MX::op(vl, dat[l ++]);
            if (r & 1)  vr = MX::op(dat[-- r], vr);
            l >>= 1, r >>= 1;
        }
        return MX::op(vl, vr);
    }

    X prod_all() { return dat[1]; } // [0, n)

    template <typename F>
    int max_right(F check, int l) {
        assert(0 <= l && l <= n && check(MX::unit()));
        if (l == n) return n;
        l += size;
        X sm = MX::unit();
        do {
            while (l % 2 == 0) l >>= 1;     // 确保在右儿子
            if (!check(MX::op(sm, dat[l]))) {
                while (l < size) {
                    l = l * 2;
                    if (check(MX::op(sm, dat[l]))) { sm = MX::op(sm, dat[l ++]); }
                }
                return l - size;
            }
            sm = MX::op(sm, dat[l ++]); // 转移到下一个相邻区间
        } while ((l & l) != l);
        return n;
    }

    template <typename F>
    int min_left(F check, int r) {
        assert(0 <= r && r <= n && check(MX::unit()));
        if (r == 0) return 0;
        r += size;
        X sm = MX::unit();
        do {
            -- r;
            while (r > 1 && (r % 2)) r >>= 1;   // 确保在左儿子
            if (!check(MX::op(dat[r], sm))) {
                while (r < size) {
                    r = r * 2 + 1;
                    if (check(MX::op(dat[r], sm))) { sm = MX::op(dat[r --], sm); }
                }
                return r + 1 - size;
            }
            sm = MX::op(dat[r], sm);
        } while ((r & -r) != r);
        return 0;
    }
};
