#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, m, Time, num[N], low[N];
vector<int> g[N];
vector<pair<int, int>> brid;

void dfs(int u, int p) {
  num[u] = low[u] = ++Time;
  for (int v: g[u]) {
    if (v == p) continue;
    if (num[v]) {
      low[u] = min(low[u], num[v]);
    } else {
      dfs(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] >= num[v]) {
        brid.emplace_back(u, v);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  for (int i = 1; i <= n; ++i) {
    if (!num[i]) dfs(i, -1);
  }
  cout << brid.size() << "\n";
  for (auto [u, v]: brid) {
    cout << u << " " << v << "\n";
  }
  return 0;
}
