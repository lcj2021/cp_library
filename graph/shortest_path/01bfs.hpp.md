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
    \ e.frm, e.cost, e.id});\n        }\n    }\n};\n#line 3 \"graph/shortest_path/01bfs.hpp\"\
    \n\ntemplate <typename T, typename GT>\ntuple<vector<T>, vector<int>> bfs01(GT\
    \ &G, int s) {\n    int n = G.n;\n    vector<T> dist(n, infty<T>);\n    vector<int>\
    \ par(n, -1);\n    deque<int> pq;\n\n    dist[s] = T(0);\n    pq.emplace_back(s);\n\
    \    while (pq.size()) {\n        auto cv = pq.front();\n        pq.pop_front();\n\
    \        for (auto &e : G[cv]) {\n            if (dist[e.to] == infty<T> || dist[e.to]\
    \ > dist[e.frm] + e.cost) {\n                dist[e.to] = dist[e.frm] + e.cost;\n\
    \                par[e.to] = e.frm;\n                if (e.cost == 0) {\n    \
    \                pq.emplace_front(e.to);\n                } else {\n         \
    \           pq.emplace_back(e.to);\n                }\n            }\n       \
    \ }\n    }\n    return {dist, par};\n}\n"
  code: "#pragma once\n#include \"graph/base.hpp\"\n\ntemplate <typename T, typename\
    \ GT>\ntuple<vector<T>, vector<int>> bfs01(GT &G, int s) {\n    int n = G.n;\n\
    \    vector<T> dist(n, infty<T>);\n    vector<int> par(n, -1);\n    deque<int>\
    \ pq;\n\n    dist[s] = T(0);\n    pq.emplace_back(s);\n    while (pq.size()) {\n\
    \        auto cv = pq.front();\n        pq.pop_front();\n        for (auto &e\
    \ : G[cv]) {\n            if (dist[e.to] == infty<T> || dist[e.to] > dist[e.frm]\
    \ + e.cost) {\n                dist[e.to] = dist[e.frm] + e.cost;\n          \
    \      par[e.to] = e.frm;\n                if (e.cost == 0) {\n              \
    \      pq.emplace_front(e.to);\n                } else {\n                   \
    \ pq.emplace_back(e.to);\n                }\n            }\n        }\n    }\n\
    \    return {dist, par};\n}"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/shortest_path/01bfs.hpp
  requiredBy: []
  timestamp: '2023-02-24 15:59:47+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1868.test.cpp
documentation_of: graph/shortest_path/01bfs.hpp
layout: document
redirect_from:
- /library/graph/shortest_path/01bfs.hpp
- /library/graph/shortest_path/01bfs.hpp.html
title: graph/shortest_path/01bfs.hpp
---
