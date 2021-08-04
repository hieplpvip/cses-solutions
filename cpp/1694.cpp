#include <bits/stdc++.h>
using namespace std;
const int N = 505;

struct Edge {
  int v, c;
};

int n, m, lev[N], ptr[N];
vector<Edge> edges;
vector<int> g[N];
queue<int> q;

void add_edge(int u, int v, int c) {
  g[u].emplace_back(edges.size());
  edges.push_back({v, c});
  g[v].emplace_back(edges.size());
  edges.push_back({u, 0});
}

bool bfs() {
  fill(lev + 1, lev + 1 + n, -1);
  lev[1] = 0;
  q.emplace(1);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int id: g[u]) {
      auto [v, c] = edges[id];
      if (lev[v] == -1 && c > 0) {
        lev[v] = lev[u] + 1;
        q.emplace(v);
      }
    }
  }
  return (lev[n] != -1);
}

int dfs(int u, int pushed) {
  if (u == n) return pushed;
  while (ptr[u] < (int)g[u].size()) {
    int id = g[u][ptr[u]++];
    auto [v, c] = edges[id];
    if (lev[v] == lev[u] + 1 && c > 0) {
      int t = dfs(v, min(pushed, c));
      if (t) {
        edges[id].c -= t;
        edges[id ^ 1].c += t;
        return t;
      }
    }
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for (int u, v, c; m--;) {
    cin >> u >> v >> c;
    add_edge(u, v, c);
  }
  long long ans = 0;
  while (true) {
    if (!bfs()) break;
    fill(ptr + 1, ptr + 1 + n, 0);
    while (int t = dfs(1, INT_MAX)) ans += t;
  }
  cout << ans;
  return 0;
}
