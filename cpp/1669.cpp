#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, m, p[N], vstart = -1, vend = -1;
vector<int> adj[N];

bool dfs(int u) {
  for (int v: adj[u]) {
    if (v == p[u]) continue;
    if (p[v]) {
      vstart = v;
      vend = u;
      return true;
    } else {
      p[v] = u;
      if (dfs(v)) return true;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  for (int i = 1; i <= n; ++i) {
    if (p[i]) continue;
    p[i] = -1;
    if (dfs(i)) break;
  }
  if (vstart == -1) {
    cout << "IMPOSSIBLE\n";
  } else {
    vector<int> vert;
    for (int u = vend; u != vstart; u = p[u]) {
      vert.emplace_back(u);
    }
    vert.emplace_back(vstart);
    vert.emplace_back(vend);
    cout << vert.size() << "\n";
    for (int u: vert) {
      cout << u << " ";
    }
    cout << "\n";
  }
  return 0;
}
