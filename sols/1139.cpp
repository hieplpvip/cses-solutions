#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, c[N], ans[N];
vector<int> g[N];
set<int> f[N];

void dfs(int u, int p) {
  f[u].emplace(c[u]);
  for (int v: g[u]) {
    if (v != p) {
      dfs(v, u);
      if (f[u].size() < f[v].size()) {
        f[u].swap(f[v]);
      }
      for (int x: f[v]) {
        f[u].emplace(x);
      }
    }
  }
  ans[u] = f[u].size();
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
  }
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  dfs(1, -1);
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " \n"[i == n];
  }
  return 0;
}
