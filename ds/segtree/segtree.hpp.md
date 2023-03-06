---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/staticrmq_seg.test.cpp
    title: test/library_checker/datastructure/staticrmq_seg.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/segtree/segtree.hpp\"\n\n// ZKW \u7EBF\u6BB5\u6811\n\
    template <class Monoid>\nstruct SegTree {\n    using MX = Monoid;\n    using X\
    \ = typename MX::value_type;\n    using value_type = X;\n    vector<X> dat;\n\
    \    int n, log, size;\n\n    SegTree() {}\n    SegTree(int n) { build(n); } \
    \   // [0, n)\n    template <typename F>\n    SegTree(int n, F f) {\n        build(n,\
    \ f);\n    }\n    SegTree(const vector<X>& v) { build(v); }\n\n    void build(int\
    \ m) {\n        build(m, [](int i) -> X { return MX::unit(); } );\n    }\n   \
    \ void build(const vector<X>& v) {\n        build(len(v), [&](int i) -> X { return\
    \ v[i]; } );\n    }\n    template <typename F>\n    void build(int m, F f) {\n\
    \        n = m;  log = 1;\n        while ((1 << log) < n)  ++ log;\n        size\
    \ = 1 << log;        // \u9664\u4E86\u53F6\u5B50\u8282\u70B9\u5916\u7684\u8282\
    \u70B9\u603B\u6570\n        dat.assign(size << 1, MX::unit());\n        for (int\
    \ i = 0; i < n; ++ i) {  // \u8D4B\u503C\u533A\u95F4[i, i]\n            dat[size\
    \ + i] = f(i);\n        }\n        for (int i = size - 1; i >= 1; -- i) {\n  \
    \          update(i);\n        }\n    }\n\n    X get(int i) { return dat[size\
    \ + i]; }\n    vector<X> get_all() {return {dat.begin() + size, dat.begin() +\
    \ size + n}; }\n\n    void update(int i) { dat[i] = MX::op(dat[2 * i], dat[2 *\
    \ i + 1]); }\n    void set(int i, const X& x) {\n        assert(i < n);\n    \
    \    dat[i += size] = x;\n        while (i >>= 1) update(i);\n    }\n\n    void\
    \ multiply(int i, const X& x) {\n        assert(i < n);\n        i += size;\n\
    \        dat[i] = MX::op(dat[i], x);\n        while (i >>= 1) update(i);\n   \
    \ }\n\n    X prod(int l, int r) {  // \u67E5\u8BE2\u533A\u95F4 [l, r)\n      \
    \  assert(0 <= l && l <= r && r <= n);\n        X vl = MX::unit(), vr = MX::unit();\n\
    \        l += size, r += size;\n        while (l < r) {\n            if (l & 1)\
    \  vl = MX::op(vl, dat[l ++]);\n            if (r & 1)  vr = MX::op(dat[-- r],\
    \ vr);\n            l >>= 1, r >>= 1;\n        }\n        return MX::op(vl, vr);\n\
    \    }\n\n    X prod_all() { return dat[1]; } // [0, n)\n\n    template <typename\
    \ F>\n    int max_right(F check, int l) {\n        assert(0 <= l && l <= n &&\
    \ check(MX::unit()));\n        if (l == n) return n;\n        l += size;\n   \
    \     X sm = MX::unit();\n        do {\n            while (l % 2 == 0) l >>= 1;\
    \     // \u786E\u4FDD\u5728\u53F3\u513F\u5B50\n            if (!check(MX::op(sm,\
    \ dat[l]))) {\n                while (l < size) {\n                    l = l *\
    \ 2;\n                    if (check(MX::op(sm, dat[l]))) { sm = MX::op(sm, dat[l\
    \ ++]); }\n                }\n                return l - size;\n            }\n\
    \            sm = MX::op(sm, dat[l ++]); // \u8F6C\u79FB\u5230\u4E0B\u4E00\u4E2A\
    \u76F8\u90BB\u533A\u95F4\n        } while ((l & l) != l);\n        return n;\n\
    \    }\n\n    template <typename F>\n    int min_left(F check, int r) {\n    \
    \    assert(0 <= r && r <= n && check(MX::unit()));\n        if (r == 0) return\
    \ 0;\n        r += size;\n        X sm = MX::unit();\n        do {\n         \
    \   -- r;\n            while (r > 1 && (r % 2)) r >>= 1;   // \u786E\u4FDD\u5728\
    \u5DE6\u513F\u5B50\n            if (!check(MX::op(dat[r], sm))) {\n          \
    \      while (r < size) {\n                    r = r * 2 + 1;\n              \
    \      if (check(MX::op(dat[r], sm))) { sm = MX::op(dat[r --], sm); }\n      \
    \          }\n                return r + 1 - size;\n            }\n          \
    \  sm = MX::op(dat[r], sm);\n        } while ((r & -r) != r);\n        return\
    \ 0;\n    }\n};\n"
  code: "#pragma once\n\n// ZKW \u7EBF\u6BB5\u6811\ntemplate <class Monoid>\nstruct\
    \ SegTree {\n    using MX = Monoid;\n    using X = typename MX::value_type;\n\
    \    using value_type = X;\n    vector<X> dat;\n    int n, log, size;\n\n    SegTree()\
    \ {}\n    SegTree(int n) { build(n); }    // [0, n)\n    template <typename F>\n\
    \    SegTree(int n, F f) {\n        build(n, f);\n    }\n    SegTree(const vector<X>&\
    \ v) { build(v); }\n\n    void build(int m) {\n        build(m, [](int i) -> X\
    \ { return MX::unit(); } );\n    }\n    void build(const vector<X>& v) {\n   \
    \     build(len(v), [&](int i) -> X { return v[i]; } );\n    }\n    template <typename\
    \ F>\n    void build(int m, F f) {\n        n = m;  log = 1;\n        while ((1\
    \ << log) < n)  ++ log;\n        size = 1 << log;        // \u9664\u4E86\u53F6\
    \u5B50\u8282\u70B9\u5916\u7684\u8282\u70B9\u603B\u6570\n        dat.assign(size\
    \ << 1, MX::unit());\n        for (int i = 0; i < n; ++ i) {  // \u8D4B\u503C\u533A\
    \u95F4[i, i]\n            dat[size + i] = f(i);\n        }\n        for (int i\
    \ = size - 1; i >= 1; -- i) {\n            update(i);\n        }\n    }\n\n  \
    \  X get(int i) { return dat[size + i]; }\n    vector<X> get_all() {return {dat.begin()\
    \ + size, dat.begin() + size + n}; }\n\n    void update(int i) { dat[i] = MX::op(dat[2\
    \ * i], dat[2 * i + 1]); }\n    void set(int i, const X& x) {\n        assert(i\
    \ < n);\n        dat[i += size] = x;\n        while (i >>= 1) update(i);\n   \
    \ }\n\n    void multiply(int i, const X& x) {\n        assert(i < n);\n      \
    \  i += size;\n        dat[i] = MX::op(dat[i], x);\n        while (i >>= 1) update(i);\n\
    \    }\n\n    X prod(int l, int r) {  // \u67E5\u8BE2\u533A\u95F4 [l, r)\n   \
    \     assert(0 <= l && l <= r && r <= n);\n        X vl = MX::unit(), vr = MX::unit();\n\
    \        l += size, r += size;\n        while (l < r) {\n            if (l & 1)\
    \  vl = MX::op(vl, dat[l ++]);\n            if (r & 1)  vr = MX::op(dat[-- r],\
    \ vr);\n            l >>= 1, r >>= 1;\n        }\n        return MX::op(vl, vr);\n\
    \    }\n\n    X prod_all() { return dat[1]; } // [0, n)\n\n    template <typename\
    \ F>\n    int max_right(F check, int l) {\n        assert(0 <= l && l <= n &&\
    \ check(MX::unit()));\n        if (l == n) return n;\n        l += size;\n   \
    \     X sm = MX::unit();\n        do {\n            while (l % 2 == 0) l >>= 1;\
    \     // \u786E\u4FDD\u5728\u53F3\u513F\u5B50\n            if (!check(MX::op(sm,\
    \ dat[l]))) {\n                while (l < size) {\n                    l = l *\
    \ 2;\n                    if (check(MX::op(sm, dat[l]))) { sm = MX::op(sm, dat[l\
    \ ++]); }\n                }\n                return l - size;\n            }\n\
    \            sm = MX::op(sm, dat[l ++]); // \u8F6C\u79FB\u5230\u4E0B\u4E00\u4E2A\
    \u76F8\u90BB\u533A\u95F4\n        } while ((l & l) != l);\n        return n;\n\
    \    }\n\n    template <typename F>\n    int min_left(F check, int r) {\n    \
    \    assert(0 <= r && r <= n && check(MX::unit()));\n        if (r == 0) return\
    \ 0;\n        r += size;\n        X sm = MX::unit();\n        do {\n         \
    \   -- r;\n            while (r > 1 && (r % 2)) r >>= 1;   // \u786E\u4FDD\u5728\
    \u5DE6\u513F\u5B50\n            if (!check(MX::op(dat[r], sm))) {\n          \
    \      while (r < size) {\n                    r = r * 2 + 1;\n              \
    \      if (check(MX::op(dat[r], sm))) { sm = MX::op(dat[r --], sm); }\n      \
    \          }\n                return r + 1 - size;\n            }\n          \
    \  sm = MX::op(dat[r], sm);\n        } while ((r & -r) != r);\n        return\
    \ 0;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree/segtree.hpp
  requiredBy: []
  timestamp: '2023-02-24 15:59:47+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/staticrmq_seg.test.cpp
documentation_of: ds/segtree/segtree.hpp
layout: document
redirect_from:
- /library/ds/segtree/segtree.hpp
- /library/ds/segtree/segtree.hpp.html
title: ds/segtree/segtree.hpp
---