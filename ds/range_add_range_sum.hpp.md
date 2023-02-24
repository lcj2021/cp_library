---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: ds/fenwicktree/fenwicktree.hpp
    title: ds/fenwicktree/fenwicktree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/range_add_query.test.cpp
    title: test/aoj/range_add_query.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/add.hpp\"\n\ntemplate <typename X>\nstruct Monoid_Add\
    \ {\n    using value_type = X;\n    static constexpr X op(const X &x, const X\
    \ &y) noexcept { return x + y; }\n    static constexpr X inverse(const X &x) noexcept\
    \ { return -x; }\n    static constexpr X power(const X &x, int n) noexcept { return\
    \ X(n) * x; }\n    static constexpr X unit() noexcept { return X(0); }\n    static\
    \ constexpr bool commute = true;   // ?\n};\n#line 3 \"ds/fenwicktree/fenwicktree.hpp\"\
    \n\ntemplate <typename Monoid>\nstruct FenwickTree {\n    using G = Monoid;\n\
    \    using E = typename G::value_type;\n    int n;\n    vector<E> dat;\n    E\
    \ total;\n    \n    FenwickTree() {}\n    FenwickTree(int n) { build(n); }\n \
    \   template <typename F>\n    FenwickTree(int n, F f) {\n        build(n, f);\n\
    \    }\n    FenwickTree(const vector<E>& v) { build(v); }\n\n    void build(int\
    \ m) {\n        n = m;\n        dat.assign(m, G::unit());\n        total = G::unit();\n\
    \    }\n    void build(const vector<E>& v) {\n        build(len(v), [&](int i)\
    \ -> E { return v[i]; } );\n    }\n    template <typename F>\n    void build(int\
    \ m, F f) {\n        n = m;\n        dat.clear();\n        dat.reserve(m);\n \
    \       total = G::unit();\n        for (int i = 0; i < n; ++ i) { dat.eb(f(i));\
    \ }\n        for (int i = 1; i <= n; ++ i) {\n            int j = i + (i & -i);\n\
    \            if (j <= n) dat[j - 1] = G::op(dat[j - 1], dat[i - 1]);\n       \
    \ }\n        total = prefix_prod(m);\n    }\n\n    E prod_all() { return total;\
    \ }\n    E prod(int k) { return prefix_prod(k); }\n    E prefix_prod(int k) {\n\
    \        k = min(k, n);\n        E ret = G::unit();\n        for (; k > 0; k -=\
    \ (k & -k)) ret = G::op(ret, dat[k - 1]);\n        return ret;\n    }\n    E prod(int\
    \ l, int r) {  // [l, r)\n        l = max(l, (int)0), r = min(r, n);\n       \
    \ if (l == 0) return prefix_prod(r);\n        assert(0 <= l && l <= r && r <=\
    \ n);\n        E pos = G::unit(), neg = G::unit();   // positive, negative\n \
    \       while (l < r) { pos = G::op(pos, dat[r - 1]), r -= (r & -r); }\n     \
    \   while (r < l) { neg = G::op(neg, dat[l - 1]), l -= (l & -l); }\n        return\
    \ G::op(pos, G::inverse(neg));\n    }\n\n    void multiply(int k, E x) {\n   \
    \     static_assert(G::commute);\n        total = G::op(total, x);\n        for\
    \ (++ k; k <= n; k += (k & -k)) dat[k - 1] = G::op(dat[k - 1], x);\n    }\n};\n\
    #line 3 \"ds/range_add_range_sum.hpp\"\n\ntemplate <typename Monoid>\nstruct RangeAddRangeSum\
    \ {\n    using MX = Monoid;\n    using E = typename MX::value_type;\n    \n  \
    \  struct Mono {   // [-i * bit[i][0], bit[i][1]]\n        using value_type =\
    \ array<E, 2>;\n        using X = value_type;\n        static X op(X x, X y) {\
    \ return {MX::op(x[0], y[0]), MX::op(x[1], y[1])}; }\n        static constexpr\
    \ X unit() { return {MX::unit(), MX::unit()}; }\n        static constexpr bool\
    \ commute = true;\n    };\n    FenwickTree<Mono> bit;\n\n    RangeAddRangeSum()\
    \ {}\n    RangeAddRangeSum(int n) { build(n); }\n    template <typename F>\n \
    \   RangeAddRangeSum(int n, F f) { build(n, f); }\n    RangeAddRangeSum(const\
    \ vector<E>& v) { build(v); }\n\n    void build(int m) {\n        build(m, [](int\
    \ i) -> E { return MX::unit(); } );\n    }\n    void build(const vector<E>& v)\
    \ {\n        build(len(v), [&](int i) -> E { return v[i]; } );\n    }\n    template\
    \ <typename F>\n    void build(int m, F f) {\n        bit.build(m, [&](int i)\
    \ -> array<E, 2> { return {f(i), MX::unit()}; });\n    }\n\n    void add(int l,\
    \ int r, E a) {   // [l, r)\n        E b = MX::inverse(a);\n        bit.multiply(l,\
    \ {MX::power(b, l), a});\n        bit.multiply(r, {MX::power(a, r), b});\n   \
    \ }\n\n    E sum(int l, int r) {   // [l, r)\n        auto [x0, x1] = bit.prod(l);\n\
    \        auto [y0, y1] = bit.prod(r);\n        E x = MX::op(MX::power(x1, l),\
    \ x0);\n        E y = MX::op(MX::power(y1, r), y0);\n        return MX::op(MX::inverse(x),\
    \ y);\n    }\n};\n"
  code: "#pragma once\n#include \"ds/fenwicktree/fenwicktree.hpp\"\n\ntemplate <typename\
    \ Monoid>\nstruct RangeAddRangeSum {\n    using MX = Monoid;\n    using E = typename\
    \ MX::value_type;\n    \n    struct Mono {   // [-i * bit[i][0], bit[i][1]]\n\
    \        using value_type = array<E, 2>;\n        using X = value_type;\n    \
    \    static X op(X x, X y) { return {MX::op(x[0], y[0]), MX::op(x[1], y[1])};\
    \ }\n        static constexpr X unit() { return {MX::unit(), MX::unit()}; }\n\
    \        static constexpr bool commute = true;\n    };\n    FenwickTree<Mono>\
    \ bit;\n\n    RangeAddRangeSum() {}\n    RangeAddRangeSum(int n) { build(n); }\n\
    \    template <typename F>\n    RangeAddRangeSum(int n, F f) { build(n, f); }\n\
    \    RangeAddRangeSum(const vector<E>& v) { build(v); }\n\n    void build(int\
    \ m) {\n        build(m, [](int i) -> E { return MX::unit(); } );\n    }\n   \
    \ void build(const vector<E>& v) {\n        build(len(v), [&](int i) -> E { return\
    \ v[i]; } );\n    }\n    template <typename F>\n    void build(int m, F f) {\n\
    \        bit.build(m, [&](int i) -> array<E, 2> { return {f(i), MX::unit()}; });\n\
    \    }\n\n    void add(int l, int r, E a) {   // [l, r)\n        E b = MX::inverse(a);\n\
    \        bit.multiply(l, {MX::power(b, l), a});\n        bit.multiply(r, {MX::power(a,\
    \ r), b});\n    }\n\n    E sum(int l, int r) {   // [l, r)\n        auto [x0,\
    \ x1] = bit.prod(l);\n        auto [y0, y1] = bit.prod(r);\n        E x = MX::op(MX::power(x1,\
    \ l), x0);\n        E y = MX::op(MX::power(y1, r), y0);\n        return MX::op(MX::inverse(x),\
    \ y);\n    }\n};"
  dependsOn:
  - ds/fenwicktree/fenwicktree.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: ds/range_add_range_sum.hpp
  requiredBy: []
  timestamp: '2023-02-14 20:51:34+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/range_add_query.test.cpp
documentation_of: ds/range_add_range_sum.hpp
layout: document
redirect_from:
- /library/ds/range_add_range_sum.hpp
- /library/ds/range_add_range_sum.hpp.html
title: ds/range_add_range_sum.hpp
---