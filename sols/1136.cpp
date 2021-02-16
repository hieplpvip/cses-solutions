#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, m, sz[N], p[N], nxt[N], Time, in[N], out[N], ans[N];
vector<int> g[N];

void dfs_sz(int u) {
  sz[u] = 1;
  for (int &v: g[u]) {
    if (v == p[u]) continue;
    p[v] = u;
    dfs_sz(v);
    sz[u] += sz[v];
    if (g[u][0] == p[u] || sz[v] > sz[g[u][0]]) {
      swap(v, g[u][0]);
    }
  }
}

void dfs_hld(int u) {
  in[u] = ++Time;
  if (nxt[u] == 0) nxt[u] = u;
  for (int v: g[u]) {
    if (v == p[u]) continue;
    if (v == g[u][0]) nxt[v] = nxt[u];
    dfs_hld(v);
  }
  out[u] = Time;
}

inline bool isdes(int u, int v) {
  return in[u] <= in[v] && out[v] <= out[u];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  dfs_sz(1); dfs_hld(1);
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    while (!isdes(nxt[u], v)) {
      ++ans[in[nxt[u]]];
      --ans[in[u] + 1];
      u = p[nxt[u]];
    }
    while (!isdes(nxt[v], u)) {
      ++ans[in[nxt[v]]];
      --ans[in[v] + 1];
      v = p[nxt[v]];
    }
    if (in[u] > in[v]) swap(u, v);
    ++ans[in[u]];
    --ans[in[v] + 1];
  }
  for (int i = 1; i <= n; ++i) {
    ans[i] += ans[i - 1];
  }
  for (int i = 1; i <= n; ++i) {
    cout << ans[in[i]] << " \n"[i == n];
  }
  return 0;
}
