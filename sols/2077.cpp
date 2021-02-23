#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, m, q, Time, num[N], low[N];
vector<int> g[N];
bool cut[N];

void dfs(int u, int p) {
  int nchild = 0;
  num[u] = low[u] = ++Time;
  for (int v: g[u]) {
    if (v == p) continue;
    if (num[v]) {
      low[u] = min(low[u], num[v]);
    } else {
      ++nchild;
      dfs(v, u);
      low[u] = min(low[u], low[v]);
      if (p != -1 && low[v] >= num[u]) {
        if (!cut[u]) ++q;
        cut[u] = true;
      }
    }
  }
  if (p == -1 && nchild >= 2) {
    if (!cut[u]) ++q;
    cut[u] = true;
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
  cout << q << "\n";
  for (int i = 1; i <= n; ++i) {
    if (cut[i]) {
      cout << i << " \n"[i == n];
    }
  }
  return 0;
}
