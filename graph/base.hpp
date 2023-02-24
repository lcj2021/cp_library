#pragma once

template <typename T>
struct Edge {
    int frm, to;
    T cost;
    int id;
};

template <typename T = int, bool directed = false>
struct Graph {
    int n, m;   
    using cost_type = T;
    using edge_type = Edge<T>;
    vector<edge_type> edges;
    vector<int> indptr;
    vector<edge_type> csr_edges;
    vector<int> deg, indeg, outdeg;
    bool prepared;

    class OutgoingEdges {
    public:
        OutgoingEdges(const Graph* G, int l, int r): G(G), l(l), r(r) {}

        const edge_type* begin() const {
            if (l == r) { return 0; }
            return &G->csr_edges[l];
        }
        const edge_type* end() const {
            if (l == r) { return 0; }
            return &G->csr_edges[r];
        }
    
    private:
        const Graph* G;
        int l, r;
    };

    Graph(): n(0), m(0), prepared(false) {}
    Graph(int n): n(n), m(0), prepared(false) {}

    void add(int frm, int to, T cost = 1, int i = -1) {
        assert(!prepared);
        assert(0 <= frm && 0 <= to && to < n);
        if (i == -1) i = m;
        auto e = edge_type({frm, to, cost, i});
        edges.emplace_back(e);
        ++ m;
    }

    OutgoingEdges operator[] (int v) const {
        assert(prepared);
        return {this, indptr[v], indptr[v + 1]};
    }

    void build() {
        assert(!prepared);
        prepared = true;
        indptr.assign(n + 1, 0);
        for (auto&& e: edges) {
            indptr[e.frm + 1]++;
            if (!directed) indptr[e.to + 1]++;
        }
        for (int v = 0; v < n; ++v) { indptr[v + 1] += indptr[v]; }
        auto counter = indptr;
        csr_edges.resize(indptr.back() + 1);
        for (auto&& e: edges) {
        csr_edges[counter[e.frm]++] = e;
        if (!directed)
            csr_edges[counter[e.to]++] = edge_type({e.to, e.frm, e.cost, e.id});
        }
    }
};
