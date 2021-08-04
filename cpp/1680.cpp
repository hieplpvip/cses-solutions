#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, m, f[N], nxt[N];
vector<int> adj[N];

void dfs(int u) {
  f[u] = (u == n) ? 1 : -1e9;
  for (int v: adj[u]) {
    if (f[v] == 0) dfs(v);
    if (f[u] < f[v] + 1) {
      f[u] = f[v] + 1;
      nxt[u] = v;
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    adj[u].emplace_back(v);
  }
  dfs(1);
  if (f[1] < 0) {
    cout << "IMPOSSIBLE\n";
  } else {
    cout << f[1] << "\n";
    for (int u = 1; u != n; u = nxt[u]) {
      cout << u << " ";
    }
    cout << n << "\n";
  }
  return 0;
}
