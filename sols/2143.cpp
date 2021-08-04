#pragma GCC target("popcnt")
#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5;

int n, nn, m, q, Time, num[N], low[N], cmp[N];
vector<int> s, adj[N], nadj[N];
bool vis[N];
bitset<N> f[N];

int tarjan(int u) {
  num[u] = low[u] = ++Time;
  s.emplace_back(u);
  for (int v: adj[u]) {
    if (!cmp[v]) {
      low[u] = min(low[u], num[v] ?: tarjan(v));
    }
  }
  if (low[u] == num[u]) {
    int v; ++nn;
    do {
      v = s.back(); s.pop_back();
      cmp[v] = nn;
    } while (v != u);
  }
  return low[u];
}

void dfs(int u) {
  vis[u] = true;
  f[u].set(u);
  for (int v: nadj[u]) {
    if (!vis[v]) dfs(v);
    f[u] |= f[v];
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m >> q;
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    adj[u].emplace_back(v);
  }
  for (int i = 1; i <= n; ++i) {
    if (!num[i]) tarjan(i);
  }
  for (int u = 1; u <= n; ++u) {
    for (int v: adj[u]) {
      if (cmp[u] != cmp[v]) {
        nadj[cmp[u]].emplace_back(cmp[v]);
      }
    }
  }
  for (int i = 1; i <= nn; ++i) {
    sort(nadj[i].begin(), nadj[i].end());
    nadj[i].resize(unique(nadj[i].begin(), nadj[i].end()) - nadj[i].begin());
  }
  for (int i = 1; i <= nn; ++i) {
    if (!vis[i]) dfs(i);
  }
  while (q--) {
    int u, v; cin >> u >> v;
    u = cmp[u]; v = cmp[v];
    cout << (u == v || f[u].test(v) ? "YES\n" : "NO\n");
  }
  return 0;
}
