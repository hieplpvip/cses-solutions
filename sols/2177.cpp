#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, m, vis, Time, num[N], low[N];
bool rem[N], hasbrid;
vector<pair<int, int>> g[N], ans;

void dfs(int u) {
  num[u] = low[u] = ++Time;
  ++vis;
  for (auto [v, id]: g[u]) {
    if (rem[id]) continue;
    rem[id] = true;
    ans.emplace_back(u, v);
    if (num[v]) {
      low[u] = min(low[u], num[v]);
    } else {
      dfs(v);
      low[u] = min(low[u], low[v]);
      if (low[v] >= num[v]) {
        hasbrid = true;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    g[u].emplace_back(v, i);
    g[v].emplace_back(u, i);
  }
  dfs(1);
  if (hasbrid || vis < n) {
    cout << "IMPOSSIBLE\n";
  } else {
    for (auto [u, v]: ans) {
      cout << u << " " << v << "\n";
    }
  }
  return 0;
}
