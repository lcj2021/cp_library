#pragma once
#include "graph/base.hpp"

template <typename T, typename GT>
tuple<vector<T>, vector<int>> bfs01(GT &G, int s) {
    int n = G.n;
    vector<T> dist(n, infty<T>);
    vector<int> par(n, -1);
    deque<int> pq;

    dist[s] = T(0);
    pq.emplace_back(s);
    while (pq.size()) {
        auto cv = pq.front();
        pq.pop_front();
        for (auto &e : G[cv]) {
            if (dist[e.to] == infty<T> || dist[e.to] > dist[e.frm] + e.cost) {
                dist[e.to] = dist[e.frm] + e.cost;
                par[e.to] = e.frm;
                if (e.cost == 0) {
                    pq.emplace_front(e.to);
                } else {
                    pq.emplace_back(e.to);
                }
            }
        }
    }
    return {dist, par};
}