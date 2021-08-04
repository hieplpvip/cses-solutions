#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n;
vector<int> g[N], c;

int dfs(int u, int p) {
  bool ok = true;
  int sz = 1;
  for (int v: g[u]) {
    if (v == p) continue;
    int t = dfs(v, u);
    if (2 * t > n) ok = false;
    sz += t;
  }
  if (ok && 2 * (n - sz) <= n) {
    c.emplace_back(u);
  }
  return sz;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  dfs(1, -1);
  cout << c[0] << "\n";
  return 0;
}
