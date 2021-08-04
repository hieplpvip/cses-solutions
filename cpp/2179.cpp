#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, m, outdeg[N], vis[N];
vector<int> g[N];
vector<pair<int, int>> E;

void dfs(int u) {
  vis[u] = 1;
  for (int v: g[u]) {
    if (vis[v] != 1) {
      if (!vis[v]) dfs(v);
      if (outdeg[v] & 1) {
        ++outdeg[v];
        E.emplace_back(v, u);
      } else {
        ++outdeg[u];
        E.emplace_back(u, v);
      }
    }
  }
  vis[u] = 2;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for (int u, v; m--;) {
    cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) dfs(i);
    if (outdeg[i] & 1) {
      cout << "IMPOSSIBLE";
      return 0;
    }
  }
  for (auto [u, v]: E) {
    cout << u << " " << v << "\n";
  }
  return 0;
}
