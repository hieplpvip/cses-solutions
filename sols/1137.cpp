#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;

int n, q, x[N], Time, in[N], out[N];
vector<int> adj[N];
ll fen[N];

void add(int p, int v) {
  for (; p <= n; p += p & -p) {
    fen[p] += v;
  }
}

ll get(int p) {
  ll v = 0;
  for (; p >= 1; p -= p & -p) {
    v += fen[p];
  }
  return v;
}

void dfs(int u, int p) {
  in[u] = ++Time;
  for (int v: adj[u]) {
    if (v != p) {
      dfs(v, u);
    }
  }
  out[u] = Time;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
  }
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  dfs(1, -1);
  for (int i = 1; i <= n; ++i) {
    add(in[i], x[i]);
  }
  while (q--) {
    int t, u; cin >> t >> u;
    if (t == 1) {
      int v; cin >> v;
      add(in[u], v - x[u]);
      x[u] = v;
    } else {
      cout << get(out[u]) - get(in[u] - 1) << "\n";
    }
  }
  return 0;
}
