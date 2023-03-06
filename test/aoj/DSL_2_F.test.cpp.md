---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/min_assign.hpp
    title: alg/acted_monoid/min_assign.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/assign.hpp
    title: alg/monoid/assign.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: ds/segtree/lazy_segtree.hpp
    title: ds/segtree/lazy_segtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F
  bundledCode: "#line 1 \"test/aoj/DSL_2_F.test.cpp\"\n#define PROBLEM \\\n    \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F\"\n\n#line 1\
    \ \"base.hpp\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#define int\
    \ long long\n#define i128 __int128\n#define endl \"\\n\"\n#define all(v) (v).begin(),\
    \ (v).end()\n#define len(v) unsigned(v.size())\n#define popcountll(x) __builtin_popcountll(x)\n\
    #define eb emplace_back\n#define stoi stoll\n\n#define MIN(v) *min_element(all(v))\n\
    #define MAX(v) *max_element(all(v))\n// #define GEQB(v, x) distance((v).begin(),\
    \ lower_bound(all(v), (x)))\n// #define LEQB(v, x) distance((v).begin(), prev(upper_bound(all(v),\
    \ (x))))\n// #define GB(v, x) distance((v).begin(), upper_bound(all(v), (x)))\n\
    // #define LB(v, x) distance((v).begin(), prev(lower_bound(all(v), (x))))\n\n\
    #define LB(v, x) distance((v).begin(), lower_bound(all(v), (x)))\n#define UB(v,\
    \ x) distance((v).begin(), upper_bound(all(v), (x)))\n#define UNIQUE(v) \\\n \
    \   sort(all(v)), v.erase(unique(all(v)), v.end()), v.shrink_to_fit()\n\ntemplate\
    \ <class T>\nusing PQ = priority_queue<T>;\ntemplate <class T>\nusing PQG = priority_queue<T,\
    \ vector<T>, greater<T>>;\n\ntemplate <class T>\nconstexpr T infty = 0;\ntemplate\
    \ <>\nconstexpr int infty<int> = 1'000'000'000'000'000'000;\ntemplate <>\nconstexpr\
    \ i128 infty<i128> = i128(infty<int>) * infty<int>;\ntemplate <>\nconstexpr double\
    \ infty<double> = infty<int>;\ntemplate <>\nconstexpr long double infty<long double>\
    \ = infty<int>;\n\nvoid YES(bool ok = 1) { cout << (ok ? \"YES\" : \"NO\") <<\
    \ endl; }\nvoid NO(bool ok = 1) { YES(!ok); }\nvoid Yes(bool ok = 1) { cout <<\
    \ (ok ? \"Yes\" : \"No\") << endl; }\nvoid No(bool ok = 1) { Yes(!ok); }\nvoid\
    \ yes(bool ok = 1) { cout << (ok ? \"yes\" : \"no\") << endl; }\nvoid no(bool\
    \ ok = 1) { yes(!ok); }\n\n#if not defined(Liucj_2022)\n#define LOG(...)\n#endif\
    \ // Liucj_2022\n#line 2 \"ds/segtree/lazy_segtree.hpp\"\n\ntemplate <typename\
    \ ActedMonoid>\nstruct LazySegTree {\n    using AM = ActedMonoid;\n    using MX\
    \ = typename AM::Monoid_X;\n    using MA = typename AM::Monoid_A;\n    using X\
    \ = typename MX::value_type;\n    using A = typename MA::value_type;\n\n    int\
    \ n, size, log;\n    vector<X> dat;\n    vector<A> laz;\n\n    LazySegTree(int\
    \ n) { build(n); }\n    template <typename F>\n    LazySegTree(int n, F f) {\n\
    \        build(n, f);\n    }\n    LazySegTree(const vector<X>& v) { build(v);\
    \ }\n\n    void build(int m) {\n        build(m, [](int i) -> X { return MX::unit();\
    \ } );\n    }\n    void build(const vector<X>& v) {\n        build(len(v), [&](int\
    \ i) -> X { return v[i]; } );\n    }\n    template <typename F>\n    void build(int\
    \ m, F f) {\n        n = m;  log = 1;\n        while ((1 << log) < m) ++ log;\n\
    \        size = 1 << log;\n        dat.assign(size << 1, MX::unit());\n      \
    \  laz.assign(size, MA::unit());\n        for (int i = 0; i < n; ++ i) dat[i +\
    \ size] = f(i);\n        for (int i = size - 1; i >= 1; -- i) update(i);\n   \
    \ }\n\n    void update(int k) { dat[k] = MX::op(dat[k * 2], dat[k * 2 + 1]); }\n\
    \n    void set(int p, X x) {\n        assert(0 <= p && p < n);\n        p += size;\n\
    \        for (int i = log; i >= 1; -- i) push(p >> i);\n        dat[p] = x;\n\
    \        for (int i = 1; i <= log; ++ i) update(p >> i);\n    }\n\n    X get(int\
    \ p) {\n        assert(0 <= p && p < n);\n        p += size;\n        for (int\
    \ i = log; i >= 1; -- i) push(p >> i);\n        return dat[p];\n    }\n\n    vector<X>\
    \ get_all() {\n        for (int i = 1; i < size; ++ i) push(i);\n        return\
    \ {dat.begin() + size, dat.begin() + size + n};\n    }\n\n    X prod(int l, int\
    \ r) {\n        assert(0 <= l && l <= r && r <= n);\n        if (l == r) return\
    \ MX::unit();\n\n        l += size, r += size;\n        for (int i = log; i >=\
    \ 1; -- i) {\n            if (((l >> i) << i) != l) push(l >> i);\n          \
    \  if (((r >> i) << i) != r) push(r - 1 >> i);\n        }\n\n        X xl = MX::unit(),\
    \ xr = MX::unit();\n        while (l < r) {\n            if (l & 1)  xl = MX::op(xl,\
    \ dat[l ++]);\n            if (r & 1)  xr = MX::op(dat[-- r], xr);\n         \
    \   l >>= 1, r >>= 1;\n        }\n        return MX::op(xl, xr);\n    }\n\n  \
    \  X prod_all() { return dat[1]; }\n\n    void apply(int l, int r, A a) {\n  \
    \      assert(0 <= l && l <= r && r <= n);\n        if (l == r) return;\n    \
    \    l += size, r += size;\n\n        // \u53EA\u9700\u8981\u4ECE\u6700\u4F4E\u6709\
    \u6548\u4F4D\u90A3\u4E00\u5C42\u5F00\u59CB\u5F80\u4E0Bpushdown\u5373\u53EF\u8986\
    \u76D6[l, r)\n        for (int i = log; i >= 1; -- i) {\n            if (((l >>\
    \ i) << i) != l) push(l >> i);\n            if (((r >> i) << i) != r) push(r -\
    \ 1 >> i);\n        }\n\n        int l2 = l, r2 = r;\n        while (l < r) {\n\
    \            if (l & 1)  apply_at(l ++, a);\n            if (r & 1)  apply_at(--\
    \ r, a);\n            l >>= 1, r >>= 1;\n        }\n        l = l2, r = r2;\n\
    \        for (int i = 1; i <= log; ++ i) {\n            if (((l >> i) << i) !=\
    \ l) update(l >> i);\n            if (((r >> i) << i) != r) update(r - 1 >> i);\n\
    \        }\n    }\n\nprivate:\n    int topbit(int x) { return (x == 0 ? -1 : 63\
    \ - __builtin_clzll(x)); }\n    void apply_at(int k, A a) {\n        int sz =\
    \ 1 << (log - topbit(k));\n        dat[k] = AM::act(dat[k], a, sz);\n        if\
    \ (k < size) laz[k] = MA::op(laz[k], a);\n    }\n    void push(int k) {\n    \
    \    if (laz[k] == MA::unit()) return;\n        apply_at(k * 2, laz[k]); apply_at(k\
    \ * 2 + 1, laz[k]);\n        laz[k] = MA::unit();\n    }\n};\n#line 2 \"alg/monoid/min.hpp\"\
    \n\ntemplate <typename X>\nstruct Monoid_Min {\n    using value_type = X;\n  \
    \  static constexpr X op(const X &x, const X &y) noexcept { return min(x, y);\
    \ }\n    static constexpr X unit() noexcept { return infty<X>; }\n    static constexpr\
    \ bool commute = true;   // ?\n};\n#line 2 \"alg/monoid/assign.hpp\"\n\ntemplate\
    \ <typename X, X none_val>\nstruct Monoid_Assign {\n    using value_type = X;\n\
    \    static X op(X x, X y) { return (y == none_val ? x : y); }\n    static constexpr\
    \ X unit() { return none_val; }\n    static constexpr bool commute = false;\n\
    };\n#line 4 \"alg/acted_monoid/min_assign.hpp\"\n\ntemplate <typename E, E none_val>\n\
    struct ActedMonoid_Min_Assign {\n    using Monoid_X = Monoid_Min<E>;\n    using\
    \ Monoid_A = Monoid_Assign<E, none_val>;\n    using X = typename Monoid_X::value_type;\n\
    \    using A = typename Monoid_A::value_type;\n    static constexpr X act(X &x,\
    \ A &a, const int &sz) {\n        if (a == none_val) return x;\n        return\
    \ a;\n    }\n};\n#line 7 \"test/aoj/DSL_2_F.test.cpp\"\n\nvoid solve() {\n   \
    \ int n, q;   cin >> n >> q;\n    using monoid = ActedMonoid_Min_Assign<int, -1>;\n\
    \    vector<int> raw(n, ((int)1 << 31) - 1);\n    LazySegTree<monoid> seg(raw);\n\
    \    while (q --) {\n        int op, s, t, x; cin >> op;\n        if (op == 0)\
    \ {\n            cin >> s >> t >> x;\n            seg.apply(s, t + 1, x);\n  \
    \      } else {\n            cin >> s >> t;\n            int ans = seg.prod(s,\
    \ t + 1);\n            cout << ans << endl;\n        }\n        LOG(seg.prod_all(),\
    \ seg.get_all())\n    }\n}\n\nsigned main() {\n    #ifdef Liucj_2022\nfreopen(\"\
    sample.in\", \"r\", stdin);\t   freopen(\"sample.out\", \"w\", stdout);\n    #endif\n\
    \    solve();\n    return 0;\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F\"\
    \n\n#include \"base.hpp\"\n#include \"ds/segtree/lazy_segtree.hpp\"\n#include\
    \ \"alg/acted_monoid/min_assign.hpp\"\n\nvoid solve() {\n    int n, q;   cin >>\
    \ n >> q;\n    using monoid = ActedMonoid_Min_Assign<int, -1>;\n    vector<int>\
    \ raw(n, ((int)1 << 31) - 1);\n    LazySegTree<monoid> seg(raw);\n    while (q\
    \ --) {\n        int op, s, t, x; cin >> op;\n        if (op == 0) {\n       \
    \     cin >> s >> t >> x;\n            seg.apply(s, t + 1, x);\n        } else\
    \ {\n            cin >> s >> t;\n            int ans = seg.prod(s, t + 1);\n \
    \           cout << ans << endl;\n        }\n        LOG(seg.prod_all(), seg.get_all())\n\
    \    }\n}\n\nsigned main() {\n    #ifdef Liucj_2022\nfreopen(\"sample.in\", \"\
    r\", stdin);\t   freopen(\"sample.out\", \"w\", stdout);\n    #endif\n    solve();\n\
    \    return 0;\n}"
  dependsOn:
  - base.hpp
  - ds/segtree/lazy_segtree.hpp
  - alg/acted_monoid/min_assign.hpp
  - alg/monoid/min.hpp
  - alg/monoid/assign.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_F.test.cpp
  requiredBy: []
  timestamp: '2023-03-06 16:29:36+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_F.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_F.test.cpp
- /verify/test/aoj/DSL_2_F.test.cpp.html
title: test/aoj/DSL_2_F.test.cpp
---
