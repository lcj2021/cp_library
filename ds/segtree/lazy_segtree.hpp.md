---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F.test.cpp
    title: test/aoj/DSL_2_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_I.test.cpp
    title: test/aoj/DSL_2_I.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/segtree/lazy_segtree.hpp\"\n\ntemplate <typename ActedMonoid>\n\
    struct LazySegTree {\n    using AM = ActedMonoid;\n    using MX = typename AM::Monoid_X;\n\
    \    using MA = typename AM::Monoid_A;\n    using X = typename MX::value_type;\n\
    \    using A = typename MA::value_type;\n\n    int n, size, log;\n    vector<X>\
    \ dat;\n    vector<A> laz;\n\n    LazySegTree(int n) { build(n); }\n    template\
    \ <typename F>\n    LazySegTree(int n, F f) {\n        build(n, f);\n    }\n \
    \   LazySegTree(const vector<X>& v) { build(v); }\n\n    void build(int m) {\n\
    \        build(m, [](int i) -> X { return MX::unit(); } );\n    }\n    void build(const\
    \ vector<X>& v) {\n        build(len(v), [&](int i) -> X { return v[i]; } );\n\
    \    }\n    template <typename F>\n    void build(int m, F f) {\n        n = m;\
    \  log = 1;\n        while ((1 << log) < m) ++ log;\n        size = 1 << log;\n\
    \        dat.assign(size << 1, MX::unit());\n        laz.assign(size, MA::unit());\n\
    \        for (int i = 0; i < n; ++ i) dat[i + size] = f(i);\n        for (int\
    \ i = size - 1; i >= 1; -- i) update(i);\n    }\n\n    void update(int k) { dat[k]\
    \ = MX::op(dat[k * 2], dat[k * 2 + 1]); }\n\n    void set(int p, X x) {\n    \
    \    assert(0 <= p && p < n);\n        p += size;\n        for (int i = log; i\
    \ >= 1; -- i) push(p >> i);\n        dat[p] = x;\n        for (int i = 1; i <=\
    \ log; ++ i) update(p >> i);\n    }\n\n    X get(int p) {\n        assert(0 <=\
    \ p && p < n);\n        p += size;\n        for (int i = log; i >= 1; -- i) push(p\
    \ >> i);\n        return dat[p];\n    }\n\n    vector<X> get_all() {\n       \
    \ for (int i = 1; i < size; ++ i) push(i);\n        return {dat.begin() + size,\
    \ dat.begin() + size + n};\n    }\n\n    X prod(int l, int r) {\n        assert(0\
    \ <= l && l <= r && r <= n);\n        if (l == r) return MX::unit();\n\n     \
    \   l += size, r += size;\n        for (int i = log; i >= 1; -- i) {\n       \
    \     if (((l >> i) << i) != l) push(l >> i);\n            if (((r >> i) << i)\
    \ != r) push(r - 1 >> i);\n        }\n\n        X xl = MX::unit(), xr = MX::unit();\n\
    \        while (l < r) {\n            if (l & 1)  xl = MX::op(xl, dat[l ++]);\n\
    \            if (r & 1)  xr = MX::op(dat[-- r], xr);\n            l >>= 1, r >>=\
    \ 1;\n        }\n        return MX::op(xl, xr);\n    }\n\n    X prod_all() { return\
    \ dat[1]; }\n\n    void apply(int l, int r, A a) {\n        assert(0 <= l && l\
    \ <= r && r <= n);\n        if (l == r) return;\n        l += size, r += size;\n\
    \n        // \u53EA\u9700\u8981\u4ECE\u6700\u4F4E\u6709\u6548\u4F4D\u90A3\u4E00\
    \u5C42\u5F00\u59CB\u5F80\u4E0Bpushdown\u5373\u53EF\u8986\u76D6[l, r)\n       \
    \ for (int i = log; i >= 1; -- i) {\n            if (((l >> i) << i) != l) push(l\
    \ >> i);\n            if (((r >> i) << i) != r) push(r - 1 >> i);\n        }\n\
    \n        int l2 = l, r2 = r;\n        while (l < r) {\n            if (l & 1)\
    \  apply_at(l ++, a);\n            if (r & 1)  apply_at(-- r, a);\n          \
    \  l >>= 1, r >>= 1;\n        }\n        l = l2, r = r2;\n        for (int i =\
    \ 1; i <= log; ++ i) {\n            if (((l >> i) << i) != l) update(l >> i);\n\
    \            if (((r >> i) << i) != r) update(r - 1 >> i);\n        }\n    }\n\
    \nprivate:\n    int topbit(int x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\n    void apply_at(int k, A a) {\n        int sz = 1 << (log - topbit(k));\n\
    \        dat[k] = AM::act(dat[k], a, sz);\n        if (k < size) laz[k] = MA::op(laz[k],\
    \ a);\n    }\n    void push(int k) {\n        if (laz[k] == MA::unit()) return;\n\
    \        apply_at(k * 2, laz[k]); apply_at(k * 2 + 1, laz[k]);\n        laz[k]\
    \ = MA::unit();\n    }\n};\n"
  code: "#pragma once\n\ntemplate <typename ActedMonoid>\nstruct LazySegTree {\n \
    \   using AM = ActedMonoid;\n    using MX = typename AM::Monoid_X;\n    using\
    \ MA = typename AM::Monoid_A;\n    using X = typename MX::value_type;\n    using\
    \ A = typename MA::value_type;\n\n    int n, size, log;\n    vector<X> dat;\n\
    \    vector<A> laz;\n\n    LazySegTree(int n) { build(n); }\n    template <typename\
    \ F>\n    LazySegTree(int n, F f) {\n        build(n, f);\n    }\n    LazySegTree(const\
    \ vector<X>& v) { build(v); }\n\n    void build(int m) {\n        build(m, [](int\
    \ i) -> X { return MX::unit(); } );\n    }\n    void build(const vector<X>& v)\
    \ {\n        build(len(v), [&](int i) -> X { return v[i]; } );\n    }\n    template\
    \ <typename F>\n    void build(int m, F f) {\n        n = m;  log = 1;\n     \
    \   while ((1 << log) < m) ++ log;\n        size = 1 << log;\n        dat.assign(size\
    \ << 1, MX::unit());\n        laz.assign(size, MA::unit());\n        for (int\
    \ i = 0; i < n; ++ i) dat[i + size] = f(i);\n        for (int i = size - 1; i\
    \ >= 1; -- i) update(i);\n    }\n\n    void update(int k) { dat[k] = MX::op(dat[k\
    \ * 2], dat[k * 2 + 1]); }\n\n    void set(int p, X x) {\n        assert(0 <=\
    \ p && p < n);\n        p += size;\n        for (int i = log; i >= 1; -- i) push(p\
    \ >> i);\n        dat[p] = x;\n        for (int i = 1; i <= log; ++ i) update(p\
    \ >> i);\n    }\n\n    X get(int p) {\n        assert(0 <= p && p < n);\n    \
    \    p += size;\n        for (int i = log; i >= 1; -- i) push(p >> i);\n     \
    \   return dat[p];\n    }\n\n    vector<X> get_all() {\n        for (int i = 1;\
    \ i < size; ++ i) push(i);\n        return {dat.begin() + size, dat.begin() +\
    \ size + n};\n    }\n\n    X prod(int l, int r) {\n        assert(0 <= l && l\
    \ <= r && r <= n);\n        if (l == r) return MX::unit();\n\n        l += size,\
    \ r += size;\n        for (int i = log; i >= 1; -- i) {\n            if (((l >>\
    \ i) << i) != l) push(l >> i);\n            if (((r >> i) << i) != r) push(r -\
    \ 1 >> i);\n        }\n\n        X xl = MX::unit(), xr = MX::unit();\n       \
    \ while (l < r) {\n            if (l & 1)  xl = MX::op(xl, dat[l ++]);\n     \
    \       if (r & 1)  xr = MX::op(dat[-- r], xr);\n            l >>= 1, r >>= 1;\n\
    \        }\n        return MX::op(xl, xr);\n    }\n\n    X prod_all() { return\
    \ dat[1]; }\n\n    void apply(int l, int r, A a) {\n        assert(0 <= l && l\
    \ <= r && r <= n);\n        if (l == r) return;\n        l += size, r += size;\n\
    \n        // \u53EA\u9700\u8981\u4ECE\u6700\u4F4E\u6709\u6548\u4F4D\u90A3\u4E00\
    \u5C42\u5F00\u59CB\u5F80\u4E0Bpushdown\u5373\u53EF\u8986\u76D6[l, r)\n       \
    \ for (int i = log; i >= 1; -- i) {\n            if (((l >> i) << i) != l) push(l\
    \ >> i);\n            if (((r >> i) << i) != r) push(r - 1 >> i);\n        }\n\
    \n        int l2 = l, r2 = r;\n        while (l < r) {\n            if (l & 1)\
    \  apply_at(l ++, a);\n            if (r & 1)  apply_at(-- r, a);\n          \
    \  l >>= 1, r >>= 1;\n        }\n        l = l2, r = r2;\n        for (int i =\
    \ 1; i <= log; ++ i) {\n            if (((l >> i) << i) != l) update(l >> i);\n\
    \            if (((r >> i) << i) != r) update(r - 1 >> i);\n        }\n    }\n\
    \nprivate:\n    int topbit(int x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\n    void apply_at(int k, A a) {\n        int sz = 1 << (log - topbit(k));\n\
    \        dat[k] = AM::act(dat[k], a, sz);\n        if (k < size) laz[k] = MA::op(laz[k],\
    \ a);\n    }\n    void push(int k) {\n        if (laz[k] == MA::unit()) return;\n\
    \        apply_at(k * 2, laz[k]); apply_at(k * 2 + 1, laz[k]);\n        laz[k]\
    \ = MA::unit();\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree/lazy_segtree.hpp
  requiredBy: []
  timestamp: '2023-03-06 16:29:36+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_I.test.cpp
  - test/aoj/DSL_2_F.test.cpp
documentation_of: ds/segtree/lazy_segtree.hpp
layout: document
redirect_from:
- /library/ds/segtree/lazy_segtree.hpp
- /library/ds/segtree/lazy_segtree.hpp.html
title: ds/segtree/lazy_segtree.hpp
---
