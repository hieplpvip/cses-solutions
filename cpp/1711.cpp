#include <bits/stdc++.h>
using namespace std;
const int N = 505;

struct Edge {
  int v, f, c;
};

int n, m, k, lev[N], ptr[N];
vector<Edge> edges;
vector<int> g[N], route;
queue<int> q;

void add_edge(int u, int v) {
  g[u].emplace_back(edges.size());
  edges.push_back({v, 0, 1});
  g[v].emplace_back(edges.size());
  edges.push_back({u, 0, 0});
}

bool bfs() {
  fill(lev + 1, lev + 1 + n, -1);
  lev[1] = 0;
  q.emplace(1);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int id: g[u]) {
      auto [v, f, c] = edges[id];
      if (lev[v] == -1 && f < c) {
        lev[v] = lev[u] + 1;
        q.emplace(v);
      }
    }
  }
  return lev[n] != -1;
}

bool dfs(int u) {
  if (u == n) return true;
  while (ptr[u] < (int)g[u].size()) {
    int id = g[u][ptr[u]++];
    auto [v, f, c] = edges[id];
    if (lev[v] == lev[u] + 1 && f < c && dfs(v)) {
      ++edges[id].f;
      --edges[id ^ 1].f;
      return true;
    }
  }
  return false;
}

void trace(int u) {
  route.emplace_back(u);
  if (u == n) return;
  while (ptr[u] < (int)g[u].size()) {
    int id = g[u][ptr[u]++];
    if (edges[id].f > 0) {
      --edges[id].f;
      ++edges[id ^ 1].f;
      trace(edges[id].v);
      return;
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for (int u, v; m--;) {
    cin >> u >> v;
    add_edge(u, v);
  }
  while (bfs()) {
    fill(ptr + 1, ptr + 1 + n, 0);
    while (dfs(1)) ++k;
  }
  cout << k << "\n";
  fill(ptr + 1, ptr + 1 + n, 0);
  while (k--) {
    route.clear();
    trace(1);
    cout << route.size() << "\n";
    for (int u: route) {
      cout << u << " ";
    }
    cout << "\n";
  }
  return 0;
}
