#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, K = 20;

int n, q, h[N], p[N][K];
vector<int> child[N];

void dfs(int u) {
  for (int v: child[u]) {
    h[v] = h[u] + 1;
    dfs(v);
  }
}

int lca(int u, int v) {
  if (h[u] < h[v]) swap(u, v);
  for (int k = K - 1; k >= 0; --k) {
    if (h[u] - (1 << k) >= h[v]) {
      u = p[u][k];
    }
  }
  if (u == v) return u;
  for (int k = K - 1; k >= 0; --k) {
    if (p[u][k] != p[v][k]) {
      u = p[u][k];
      v = p[v][k];
    }
  }
  return p[u][0];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> q;
  memset(p, -1, sizeof(p));
  for (int i = 2; i <= n; ++i) {
    cin >> p[i][0];
    child[p[i][0]].emplace_back(i);
  }
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
    cout << lca(u, v) << "\n";
  }
  return 0;
}
