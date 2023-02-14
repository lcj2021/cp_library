#pragma once
#include "ds/fenwicktree/fenwicktree.hpp"

template <typename Monoid>
struct RangeAddRangeSum {
    using MX = Monoid;
    using E = typename MX::value_type;
    
    struct Mono {   // [-i * bit[i][0], bit[i][1]]
        using value_type = array<E, 2>;
        using X = value_type;
        static X op(X x, X y) { return {MX::op(x[0], y[0]), MX::op(x[1], y[1])}; }
        static constexpr X unit() { return {MX::unit(), MX::unit()}; }
        static constexpr bool commute = true;
    };
    FenwickTree<Mono> bit;

    RangeAddRangeSum() {}
    RangeAddRangeSum(int n) { build(n); }
    template <typename F>
    RangeAddRangeSum(int n, F f) { build(n, f); }
    RangeAddRangeSum(const vector<E>& v) { build(v); }

    void build(int m) {
        build(m, [](int i) -> E { return MX::unit(); } );
    }
    void build(const vector<E>& v) {
        build(len(v), [&](int i) -> E { return v[i]; } );
    }
    template <typename F>
    void build(int m, F f) {
        bit.build(m, [&](int i) -> array<E, 2> { return {f(i), MX::unit()}; });
    }

    void add(int l, int r, E a) {   // [l, r)
        E b = MX::inverse(a);
        bit.multiply(l, {MX::power(b, l), a});
        bit.multiply(r, {MX::power(a, r), b});
    }

    E sum(int l, int r) {   // [l, r)
        auto [x0, x1] = bit.prod(l);
        auto [y0, y1] = bit.prod(r);
        E x = MX::op(MX::power(x1, l), x0);
        E y = MX::op(MX::power(y1, r), y0);
        return MX::op(MX::inverse(x), y);
    }
};