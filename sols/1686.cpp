#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, nn, m, k[N], Time, num[N], low[N], cmp[N];
vector<int> g[N], ng[N], s;
long long f[N];
bool vis[N];

int tarjan(int u) {
  num[u] = low[u] = ++Time;
  s.emplace_back(u);
  for (int v: g[u]) {
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
  long long mx = 0;
  for (int v: ng[u]) {
    if (!vis[v]) dfs(v);
    mx = max(mx, f[v]);
  }
  f[u] += mx;
  vis[u] = true;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> k[i];
  }
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    g[u].emplace_back(v);
  }
  for (int i = 1; i <= n; ++i) {
    if (!num[i]) tarjan(i);
  }
  for (int u = 1; u <= n; ++u) {
    f[cmp[u]] += k[u];
    for (int v: g[u]) {
      if (cmp[u] != cmp[v]) {
        ng[cmp[u]].emplace_back(cmp[v]);
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= nn; ++i) {
    if (!vis[i]) dfs(i);
    ans = max(ans, f[i]);
  }
  cout << ans << "\n";
  return 0;
}
