#include <bits/stdc++.h>
using namespace std;
const int N = 105;

struct Edge {
  int v, f, c;
};

int n, s, t, sumrow, sumcol, lev[N], ptr[N];
bool chosen[N][N];
vector<Edge> edges;
vector<int> g[N];
queue<int> q;

void add_edge(int u, int v, int c) {
  g[u].emplace_back(edges.size());
  edges.push_back({v, 0, c});
  g[v].emplace_back(edges.size());
  edges.push_back({u, 0, 0});
}

bool bfs() {
  memset(lev, -1, sizeof(lev));
  lev[s] = 0;
  q.emplace(s);
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
  return lev[t] != -1;
}

bool dfs(int u) {
  if (u == t) return true;
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

int main() {
  cin >> n;
  s = 0;
  t = 2 * n + 1;
  for (int i = 1, c; i <= n; ++i) {
    cin >> c;
    sumrow += c;
    if (c) add_edge(s, i, c);
  }
  for (int j = 1, c; j <= n; ++j) {
    cin >> c;
    sumcol += c;
    if (c) add_edge(n + j, t, c);
  }
  if (sumrow != sumcol) {
    cout << "-1\n";
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      add_edge(i, n + j, 1);
    }
  }
  int flow = 0;
  while (bfs()) {
    memset(ptr, 0, sizeof(ptr));
    while (dfs(s)) ++flow;
  }
  if (flow < sumrow) {
    cout << "-1\n";
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    for (int id: g[i]) {
      if (edges[id].f == 1) {
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
