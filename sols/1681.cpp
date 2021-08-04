#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, MOD = 1e9 + 7;

int n, m, f[N];
vector<int> g[N];
bool vis[N];

void dfs(int u) {
  f[u] = (u == n);
  vis[u] = true;
  for (int v: g[u]) {
    if (!vis[v]) {
      dfs(v);
    }
    f[u] += f[v];
    if (f[u] >= MOD) {
      f[u] -= MOD;
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    g[u].emplace_back(v);
  }
  dfs(1);
  cout << f[1] << "\n";
  return 0;
}
