#pragma GCC target("popcnt")
#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5;

int n, m;
bool vis[N];
vector<int> adj[N];
bitset<N> f[N];

void dfs(int u) {
  vis[u] = true;
  f[u].set(u);
  for (int v: adj[u]) {
    if (!vis[v]) dfs(v);
    f[u] |= f[v];
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    adj[u].emplace_back(v);
  }
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) dfs(i);
    cout << f[i].count() << " \n"[i == n];
  }
  return 0;
}
