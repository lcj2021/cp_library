---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: graph/range_to_range_graph.hpp
    title: graph/range_to_range_graph.hpp
  - icon: ':x:'
    path: graph/shortest_path/01bfs.hpp
    title: graph/shortest_path/01bfs.hpp
  - icon: ':warning:'
    path: graph/shortest_path/dijkstra.hpp
    title: graph/shortest_path/dijkstra.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1868.test.cpp
    title: test/yukicoder/1868.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
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
    \ e.frm, e.cost, e.id});\n        }\n    }\n};\n"
  code: "#pragma once\n\ntemplate <typename T>\nstruct Edge {\n    int frm, to;\n\
    \    T cost;\n    int id;\n};\n\ntemplate <typename T = int, bool directed = false>\n\
    struct Graph {\n    int n, m;   \n    using cost_type = T;\n    using edge_type\
    \ = Edge<T>;\n    vector<edge_type> edges;\n    vector<int> indptr;\n    vector<edge_type>\
    \ csr_edges;\n    vector<int> deg, indeg, outdeg;\n    bool prepared;\n\n    class\
    \ OutgoingEdges {\n    public:\n        OutgoingEdges(const Graph* G, int l, int\
    \ r): G(G), l(l), r(r) {}\n\n        const edge_type* begin() const {\n      \
    \      if (l == r) { return 0; }\n            return &G->csr_edges[l];\n     \
    \   }\n        const edge_type* end() const {\n            if (l == r) { return\
    \ 0; }\n            return &G->csr_edges[r];\n        }\n    \n    private:\n\
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
    \ e.frm, e.cost, e.id});\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/base.hpp
  requiredBy:
  - graph/range_to_range_graph.hpp
  - graph/shortest_path/dijkstra.hpp
  - graph/shortest_path/01bfs.hpp
  timestamp: '2023-02-24 15:59:47+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1868.test.cpp
documentation_of: graph/base.hpp
layout: document
redirect_from:
- /library/graph/base.hpp
- /library/graph/base.hpp.html
title: graph/base.hpp
---
