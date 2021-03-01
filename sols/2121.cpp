#include <bits/stdc++.h>
using namespace std;
const int N = 505, INF = 1e9;

struct Edge {
  int v, flow, cap, cost;
};

int n, m, k, pi[N], dist[N], par[N], ptr[N];
vector<Edge> edges;
vector<int> g[N], route;
priority_queue<pair<int, int>> q;

void add_edge(int u, int v, int cap, int cost) {
  g[u].emplace_back(edges.size());
  edges.push_back({v, 0, cap, cost});
  g[v].emplace_back(edges.size());
  edges.push_back({u, 0, 0, -cost});
}

void path() {
  fill(dist + 1, dist + 1 + n, INF);
  q.emplace(dist[1] = 0, 1);
  while (!q.empty()) {
    auto [du, u] = q.top(); q.pop();
    du = -du;
    if (du != dist[u]) continue;
    for (int id: g[u]) {
      auto &e = edges[id];
      int val = du + e.cost + pi[u] - pi[e.v];
      if (e.flow < e.cap && dist[e.v] > val) {
        dist[e.v] = val;
        par[e.v] = id ^ 1;
        q.emplace(-dist[e.v], e.v);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m >> k;
  for (int u, v, cap, cost; m--;) {
    cin >> u >> v >> cap >> cost;
    add_edge(u, v, cap, cost);
  }
  while (k > 0) {
    if ((path(), dist[n] == INF)) {
      cout << "-1\n";
      return 0;
    }
    for (int i = 1; i <= n; ++i) {
      pi[i] = min(pi[i] + dist[i], INF);
    }
    int push = k;
    for (int u = n; u != 1; u = edges[par[u]].v) {
      push = min(push, edges[par[u] ^ 1].cap - edges[par[u] ^ 1].flow);
    }
    for (int u = n; u != 1; u = edges[par[u]].v) {
      edges[par[u] ^ 1].flow += push;
      edges[par[u]].flow -= push;
    }
    k -= push;
  }
  int cost = 0;
  for (auto &e: edges) {
    if (e.cap) cost += e.flow * e.cost;
  }
  cout << cost << "\n";
  return 0;
}
