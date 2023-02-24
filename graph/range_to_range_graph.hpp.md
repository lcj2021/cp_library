---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1868.test.cpp
    title: test/yukicoder/1868.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://codeforces.com/problemset/problem/787/D
  bundledCode: "#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n\
    \    int frm, to;\n    T cost;\n    int id;\n};\n\ntemplate <typename T = int,\
    \ bool directed = false>\nstruct Graph {\n    int n, m;   \n    using cost_type\
    \ = T;\n    using edge_type = Edge<T>;\n    vector<edge_type> edges;\n    vector<int>\
    \ indptr;\n    vector<edge_type> csr_edges;\n    vector<int> deg, indeg, outdeg;\n\
    \    bool prepared;\n\n    class OutgoingEdges {\n    public:\n        OutgoingEdges(const\
    \ Graph* G, int l, int r): G(G), l(l), r(r) {}\n\n        const edge_type* begin()\
    \ const {\n            if (l == r) { return 0; }\n            return &G->csr_edges[l];\n\
    \        }\n        const edge_type* end() const {\n            if (l == r) {\
    \ return 0; }\n            return &G->csr_edges[r];\n        }\n    \n    private:\n\
    \        const Graph* G;\n        int l, r;\n    };\n\n    Graph(): n(0), m(0),\
    \ prepared(false) {}\n    Graph(int n): n(n), m(0), prepared(false) {}\n\n   \
    \ void add(int frm, int to, T cost = 1, int i = -1) {\n        assert(!prepared);\n\
    \        assert(0 <= frm && 0 <= to && to < n);\n        if (i == -1) i = m;\n\
    \        auto e = edge_type({frm, to, cost, i});\n        edges.emplace_back(e);\n\
    \        ++ m;\n    }\n\n    OutgoingEdges operator[] (int v) const {\n      \
    \  assert(prepared);\n        return {this, indptr[v], indptr[v + 1]};\n    }\n\
    \n    void build() {\n        assert(!prepared);\n        prepared = true;\n \
    \       indptr.assign(n + 1, 0);\n        for (auto&& e: edges) {\n          \
    \  indptr[e.frm + 1]++;\n            if (!directed) indptr[e.to + 1]++;\n    \
    \    }\n        for (int v = 0; v < n; ++v) { indptr[v + 1] += indptr[v]; }\n\
    \        auto counter = indptr;\n        csr_edges.resize(indptr.back() + 1);\n\
    \        for (auto&& e: edges) {\n        csr_edges[counter[e.frm]++] = e;\n \
    \       if (!directed)\n            csr_edges[counter[e.to]++] = edge_type({e.to,\
    \ e.frm, e.cost, e.id});\n        }\n    }\n};\n#line 3 \"graph/range_to_range_graph.hpp\"\
    \n// https://codeforces.com/problemset/problem/787/D Legacy\ntemplate <typename\
    \ T>\nstruct RangeToRangeGraph {\n    int n, n_node;\n    vector<tuple<int, int,\
    \ T>> edge;\n    RangeToRangeGraph () {}\n    RangeToRangeGraph(int n): n(n),\
    \ n_node(3 * n) {\n        for (int i = 2; i < 2 * n; ++ i) {\n            add(to_upper_idx(i\
    \ / 2), to_upper_idx(i), T(0));\n            add(to_lower_idx(i), to_lower_idx(i\
    \ / 2), T(0));\n        }\n    }\n    inline int to_upper_idx(const int& i) {\n\
    \        if (i >= n) return i - n;\n        return n + i;\n    }\n    inline int\
    \ to_lower_idx(const int& i) {\n        if (i >= n) return i - n;\n        return\
    \ n + n + i;\n    }\n    void add_frm_range(int frm_l, int frm_r, int to, T w)\
    \ {\n        int l = frm_l + n, r = frm_r + n;\n        while (l < r) {\n    \
    \        // l++ \u8981\u5BF9\u5E94\u4E0A\u7EBF\u6BB5\u6811\u4E0A\u7684\u8282\u70B9\
    \u7F16\u53F7, \u6240\u4EE5\u8981\u52A0\u4E0Ato_lower_idx()\n            if (l\
    \ & 1)  add(to_lower_idx(l ++), to, w); \n            if (r & 1)  add(to_lower_idx(--\
    \ r), to, w);\n            l >>= 1, r >>= 1;\n        }\n    }\n    void add_to_range(int\
    \ frm, int to_l, int to_r, T w) {\n        int l = to_l + n, r = to_r + n;\n \
    \       while (l < r) {\n            if (l & 1)  add(frm, to_upper_idx(l ++),\
    \ w);\n            if (r & 1)  add(frm, to_upper_idx(-- r), w);\n            l\
    \ >>= 1, r >>= 1;\n        }\n    }\n    void add_range_to_range(int frm_l, int\
    \ frm_r, int to_l, int to_r, T w) {\n        int node = n_node ++;\n        add_frm_range(frm_l,\
    \ frm_r, node, w);\n        add_to_range(node, to_l, to_r, T(0));\n    }\n   \
    \ void add(int frm, int to, T w) {\n        edge.emplace_back(frm, to, w);\n \
    \   }\n\n    Graph<T, 1> build() {\n        Graph<T, 1> G(n_node);\n        for\
    \ (auto &[u, v, w] : edge) G.add(u, v, w);\n        G.build();\n        return\
    \ G;\n    }\n};\n"
  code: "#pragma once \n#include \"base.hpp\"\n// https://codeforces.com/problemset/problem/787/D\
    \ Legacy\ntemplate <typename T>\nstruct RangeToRangeGraph {\n    int n, n_node;\n\
    \    vector<tuple<int, int, T>> edge;\n    RangeToRangeGraph () {}\n    RangeToRangeGraph(int\
    \ n): n(n), n_node(3 * n) {\n        for (int i = 2; i < 2 * n; ++ i) {\n    \
    \        add(to_upper_idx(i / 2), to_upper_idx(i), T(0));\n            add(to_lower_idx(i),\
    \ to_lower_idx(i / 2), T(0));\n        }\n    }\n    inline int to_upper_idx(const\
    \ int& i) {\n        if (i >= n) return i - n;\n        return n + i;\n    }\n\
    \    inline int to_lower_idx(const int& i) {\n        if (i >= n) return i - n;\n\
    \        return n + n + i;\n    }\n    void add_frm_range(int frm_l, int frm_r,\
    \ int to, T w) {\n        int l = frm_l + n, r = frm_r + n;\n        while (l\
    \ < r) {\n            // l++ \u8981\u5BF9\u5E94\u4E0A\u7EBF\u6BB5\u6811\u4E0A\u7684\
    \u8282\u70B9\u7F16\u53F7, \u6240\u4EE5\u8981\u52A0\u4E0Ato_lower_idx()\n     \
    \       if (l & 1)  add(to_lower_idx(l ++), to, w); \n            if (r & 1) \
    \ add(to_lower_idx(-- r), to, w);\n            l >>= 1, r >>= 1;\n        }\n\
    \    }\n    void add_to_range(int frm, int to_l, int to_r, T w) {\n        int\
    \ l = to_l + n, r = to_r + n;\n        while (l < r) {\n            if (l & 1)\
    \  add(frm, to_upper_idx(l ++), w);\n            if (r & 1)  add(frm, to_upper_idx(--\
    \ r), w);\n            l >>= 1, r >>= 1;\n        }\n    }\n    void add_range_to_range(int\
    \ frm_l, int frm_r, int to_l, int to_r, T w) {\n        int node = n_node ++;\n\
    \        add_frm_range(frm_l, frm_r, node, w);\n        add_to_range(node, to_l,\
    \ to_r, T(0));\n    }\n    void add(int frm, int to, T w) {\n        edge.emplace_back(frm,\
    \ to, w);\n    }\n\n    Graph<T, 1> build() {\n        Graph<T, 1> G(n_node);\n\
    \        for (auto &[u, v, w] : edge) G.add(u, v, w);\n        G.build();\n  \
    \      return G;\n    }\n};"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/range_to_range_graph.hpp
  requiredBy: []
  timestamp: '2023-02-24 15:59:47+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1868.test.cpp
documentation_of: graph/range_to_range_graph.hpp
layout: document
redirect_from:
- /library/graph/range_to_range_graph.hpp
- /library/graph/range_to_range_graph.hpp.html
title: graph/range_to_range_graph.hpp
---
