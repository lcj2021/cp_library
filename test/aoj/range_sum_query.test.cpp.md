---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: ds/fenwicktree/fenwicktree.hpp
    title: ds/fenwicktree/fenwicktree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
  bundledCode: "#line 1 \"test/aoj/range_sum_query.test.cpp\"\n#define PROBLEM \\\n\
    \    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\n\n\
    #line 1 \"base.hpp\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#define\
    \ int long long\n#define i128 __int128\n#define endl \"\\n\"\n#define all(v) (v).begin(),\
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
    \ // Liucj_2022\n#line 2 \"alg/monoid/add.hpp\"\n\ntemplate <typename X>\nstruct\
    \ Monoid_Add {\n    using value_type = X;\n    static constexpr X op(const X &x,\
    \ const X &y) noexcept { return x + y; }\n    static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\n    static constexpr X power(const X &x, int\
    \ n) noexcept { return X(n) * x; }\n    static constexpr X unit() noexcept { return\
    \ X(0); }\n    static constexpr bool commute = true;   // ?\n};\n#line 3 \"ds/fenwicktree/fenwicktree.hpp\"\
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
    #line 6 \"test/aoj/range_sum_query.test.cpp\"\n\nvoid solve() {\n    int n, q;\
    \   cin >> n >> q;\n    using monoid = Monoid_Add<int>;\n    FenwickTree<monoid>\
    \ bit(n);\n    while (q --) {\n        int op, x, y; cin >> op >> x >> y;\n  \
    \      if (op == 0) {\n            bit.multiply(x - 1, y);\n        } else {\n\
    \            cout << bit.prod(x - 1, y - 1 + 1) << endl;\n        }\n    }\n}\n\
    \nsigned main() {\n    solve();\n    return 0;\n}\n"
  code: "#define PROBLEM \\\n    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#include \"base.hpp\"\n#include \"ds/fenwicktree/fenwicktree.hpp\"\n\nvoid\
    \ solve() {\n    int n, q;   cin >> n >> q;\n    using monoid = Monoid_Add<int>;\n\
    \    FenwickTree<monoid> bit(n);\n    while (q --) {\n        int op, x, y; cin\
    \ >> op >> x >> y;\n        if (op == 0) {\n            bit.multiply(x - 1, y);\n\
    \        } else {\n            cout << bit.prod(x - 1, y - 1 + 1) << endl;\n \
    \       }\n    }\n}\n\nsigned main() {\n    solve();\n    return 0;\n}"
  dependsOn:
  - base.hpp
  - ds/fenwicktree/fenwicktree.hpp
  - alg/monoid/add.hpp
  isVerificationFile: true
  path: test/aoj/range_sum_query.test.cpp
  requiredBy: []
  timestamp: '2023-02-24 15:59:47+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/range_sum_query.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/range_sum_query.test.cpp
- /verify/test/aoj/range_sum_query.test.cpp.html
title: test/aoj/range_sum_query.test.cpp
---
