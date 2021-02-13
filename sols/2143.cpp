#pragma GCC target("popcnt")
#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5;

int n, nn, m, q, par[N];
int Time, num[N], low[N];
vector<int> s, adj[N], nadj[N];
unordered_map<int, int> mp;
bool vis[N];
bitset<N> f[N];

int root(int v) {
  return (par[v] < 0) ? v : (par[v] = root(par[v]));
}

void join(int x, int y) {
  if ((x = root(x)) == (y = root(y))) return;
  if (par[x] > par[y]) swap(x, y);
  par[x] += par[y];
  par[y] = x;
}

void tarjan(int u) {
  num[u] = low[u] = ++Time;
  s.emplace_back(u);
  for (int v: adj[u]) {
    if (num[v]) {
      low[u] = min(low[u], num[v]);
    } else {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    }
  }
  if (low[u] == num[u]) {
    int v;
    do {
      v = s.back(); s.pop_back();
      join(u, v);
      num[v] = low[v] = 1e9;
    } while (v != u);
  }
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
  fill(par + 1, par + 1 + n, -1);
  for (int i = 1; i <= n; ++i) {
    if (!num[i]) tarjan(i);
  }
  for (int i = 1; i <= n; ++i) {
    if (par[i] < 0) {
      mp[i] = ++nn;
    }
  }
  for (int u = 1; u <= n; ++u) {
    for (int v: adj[u]) {
      if (root(u) != root(v)) {
        nadj[mp[root(u)]].emplace_back(mp[root(v)]);
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
    u = mp[root(u)]; v = mp[root(v)];
    cout << (u == v || f[u].test(v) ? "YES\n" : "NO\n");
  }
  return 0;
}
