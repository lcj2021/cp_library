#define PROBLEM "https://yukicoder.me/problems/no/1868"
#include "base.hpp"
#include "graph/range_to_range_graph.hpp"
#include "graph/shortest_path/01bfs.hpp"

void solve() {
    int n;  cin >> n;
    RangeToRangeGraph<int> RRG(n);
    for (int i = 0; i < n - 1; ++ i) {
        int r;  cin >> r;
        RRG.add_to_range(i, i, r, 1);
    }
    auto G = RRG.build();
    auto [dist, par] = bfs01<int>(G, 0);
    cout << dist[n - 1] << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    #ifdef Liucj_2022
freopen("sample.in", "r", stdin);	   freopen("sample.out", "w", stdout);
    #endif
    solve();
    return 0;
}