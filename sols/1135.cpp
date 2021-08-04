#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, K = 20;

int n, q, h[N], p[N][K];
vector<int> adj[N];

void dfs(int u) {
  for (int v: adj[u]) {
    if (v != p[u][0]) {
      h[v] = h[u] + 1;
      p[v][0] = u;
      dfs(v);
    }
  }
}

int distance(int u, int v) {
  int res = 0;
  if (h[u] < h[v]) swap(u, v);
  for (int k = K - 1; k >= 0; --k) {
    if (h[u] - (1 << k) >= h[v]) {
      u = p[u][k];
      res += 1 << k;
    }
  }
  if (u == v) return res;
  for (int k = K - 1; k >= 0; --k) {
    if (p[u][k] != p[v][k]) {
      u = p[u][k];
      v = p[v][k];
      res += 1 << (k + 1);
    }
  }
  return res + 2;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> q;
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  memset(p, -1, sizeof(p));
  dfs(1);
  for (int k = 1; (1 << k) <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      if (p[i][k - 1] != -1) {
        p[i][k] = p[p[i][k - 1]][k - 1];
      }
    }
  }
  while (q--) {
    int u, v; cin >> u >> v;
    cout << distance(u, v) << "\n";
  }
  return 0;
}
