#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, q, x[N], y[N], p[N], sz[N], nxt[N], Time, in[N], out[N], ST[2 * N];
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
  in[u] = Time++;
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

void build() {
  for (int p = n - 1; p > 0; --p) {
    ST[p] = max(ST[p << 1], ST[p << 1 | 1]);
  }
}

void update(int p, int v) {
  for (ST[p += n] = v; p > 1; p >>= 1) {
    ST[p >> 1] = max(ST[p], ST[p ^ 1]);
  }
}

int get(int l, int r) {
  int res = INT_MIN;
  for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res = max(res, ST[l++]);
    if (r & 1) res = max(res, ST[--r]);
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
  }
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  dfs_sz(1); dfs_hld(1);
  for (int i = 1; i <= n; ++i) {
    ST[n + in[i]] = x[i];
  }
  build();
  while (q--) {
    int t, u, v; cin >> t >> u >> v;
    if (t == 1) {
      update(in[u], v);
    } else {
      int ans = INT_MIN;
      while (!isdes(nxt[u], v)) {
        ans = max(ans, get(in[nxt[u]], in[u]));
        u = p[nxt[u]];
      }
      while (!isdes(nxt[v], u)) {
        ans = max(ans, get(in[nxt[v]], in[v]));
        v = p[nxt[v]];
      }
      if (in[u] > in[v]) swap(u, v);
      ans = max(ans, get(in[u], in[v]));
      cout << ans << "\n";
    }
  }
  return 0;
}
