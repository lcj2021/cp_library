#pragma once 
#include "base.hpp"
// https://codeforces.com/problemset/problem/787/D Legacy
template <typename T>
struct RangeToRangeGraph {
    int n, n_node;
    vector<tuple<int, int, T>> edge;
    RangeToRangeGraph () {}
    RangeToRangeGraph(int n): n(n), n_node(3 * n) {
        for (int i = 2; i < 2 * n; ++ i) {
            add(to_upper_idx(i / 2), to_upper_idx(i), T(0));
            add(to_lower_idx(i), to_lower_idx(i / 2), T(0));
        }
    }
    inline int to_upper_idx(const int& i) {
        if (i >= n) return i - n;
        return n + i;
    }
    inline int to_lower_idx(const int& i) {
        if (i >= n) return i - n;
        return n + n + i;
    }
    void add_frm_range(int frm_l, int frm_r, int to, T w) {
        int l = frm_l + n, r = frm_r + n;
        while (l < r) {
            // l++ 要对应上线段树上的节点编号, 所以要加上to_lower_idx()
            if (l & 1)  add(to_lower_idx(l ++), to, w); 
            if (r & 1)  add(to_lower_idx(-- r), to, w);
            l >>= 1, r >>= 1;
        }
    }
    void add_to_range(int frm, int to_l, int to_r, T w) {
        int l = to_l + n, r = to_r + n;
        while (l < r) {
            if (l & 1)  add(frm, to_upper_idx(l ++), w);
            if (r & 1)  add(frm, to_upper_idx(-- r), w);
            l >>= 1, r >>= 1;
        }
    }
    void add_range_to_range(int frm_l, int frm_r, int to_l, int to_r, T w) {
        int node = n_node ++;
        add_frm_range(frm_l, frm_r, node, w);
        add_to_range(node, to_l, to_r, T(0));
    }
    void add(int frm, int to, T w) {
        edge.emplace_back(frm, to, w);
    }

    Graph<T, 1> build() {
        Graph<T, 1> G(n_node);
        for (auto &[u, v, w] : edge) G.add(u, v, w);
        G.build();
        return G;
    }
};