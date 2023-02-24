#pragma once
#include "graph/base.hpp"

template <typename T, typename GT>
tuple<vector<T>, vector<int>> dijkstra(GT &G, int s) {
    int n = G.n;
    vector<T> dist(n, infty<T>);
    vector<int> par(n, -1);
    using P = tuple<T, int>;
    priority_queue<P, vector<P>, greater<P>> pq;

    dist[s] = T(0);
    pq.emplace(dist[s], s);
    while (pq.size()) {
        auto [cd, cv] = pq.top();
        pq.pop();
        if (cd > dist[cv]) continue;
        for (auto &e : G[cv]) {
            if (dist[e.to] > dist[e.frm] + e.cost) {
                dist[e.to] = dist[e.frm] + e.cost;
                par[e.to] = e.frm;
                pq.emplace(dist[e.to], e.to);
            }
        }
    }
    return {dist, par};
}