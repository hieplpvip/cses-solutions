#include <bits/stdc++.h>
using namespace std;
const int N = 105, INF = 1e9;

struct Edge {
  int v, flow, cap, cost;
};

int n, s, t, sumrow, sumcol, pi[N], dist[N], ptr[N], par[N];
bool chosen[N][N];
vector<Edge> edges;
vector<int> g[N];
priority_queue<pair<int, int>> q;

void add_edge(int u, int v, int cap, int cost) {
  g[u].emplace_back(edges.size());
  edges.push_back({v, 0, cap, cost});
  g[v].emplace_back(edges.size());
  edges.push_back({u, 0, 0, -cost});
}

void setpi() {
  fill(pi, pi + 1 + t, INF);
  pi[s] = 0;
  for (int i = 0; i < t; ++i) {
    for (int u = 1; u <= t; ++u) {
      if (pi[u] == INF) continue;
      for (int id: g[u]) {
        auto &e = edges[id];
        if (e.cap) {
          pi[e.v] = min(pi[e.v], pi[u] + e.cost);
        }
      }
    }
  }
}

void path() {
  fill(dist, dist + 1 + t, INF);
  q.emplace(dist[s] = 0, s);
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
  cin >> n;
  s = 0;
  t = 2 * n + 1;
  for (int i = 1, c; i <= n; ++i) {
    cin >> c;
    sumrow += c;
    if (c) add_edge(s, i, c, 0);
  }
  for (int j = 1, c; j <= n; ++j) {
    cin >> c;
    sumcol += c;
    if (c) add_edge(n + j, t, c, 0);
  }
  for (int i = 1, c; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> c;
      add_edge(i, n + j, 1, -c);
    }
  }
  if (sumrow != sumcol) {
    cout << "-1\n";
    return 0;
  }
  int flow = 0, cost = 0;
  setpi();
  while (true) {
    if ((path(), dist[t] == INF)) break;
    for (int i = 0; i <= t; ++i) {
      pi[i] = min(pi[i] + dist[i], INF);
    }
    for (int u = t; u != s; u = edges[par[u]].v) {
      ++edges[par[u] ^ 1].flow;
      --edges[par[u]].flow;
    }
    ++flow;
  }
  if (flow < sumrow) {
    cout << "-1\n";
    return 0;
  }
  for (auto &e: edges) {
    if (e.cap) cost += e.cost * e.flow;
  }
  cout << -cost << "\n";
  for (int i = 1; i <= n; ++i) {
    for (int id: g[i]) {
      if (edges[id].flow == 1) {
        chosen[i][edges[id].v - n] = true;
      }
    }
    for (int j = 1; j <= n; ++j) {
      cout << (chosen[i][j] ? 'X' : '.');
    }
    cout << "\n";
  }
  return 0;
}
