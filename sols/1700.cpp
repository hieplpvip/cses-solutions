#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define emb emplace_back
using namespace std;
using vi = vector<int>;

struct Ahu {
  int n, cnt = 0;
  vector<vi> g1, g2;
  map<vi, int> mp;
  int dfs(vector<vi> &g, int u, int p = -1) {
    vi id;
    for (int v: g[u])
      if (v != p) id.emb(dfs(g, v, u));
    sort(all(id));
    if (!mp.count(id)) mp[id] = ++cnt;
    return mp[id];
  }
  bool check() {
    return (dfs(g1, 0) == dfs(g2, 0));
  }
};

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int T; cin >> T;
  Ahu ahu;
  while (T--) {
    Ahu ahu;
    cin >> ahu.n;
    ahu.g1.resize(ahu.n);
    ahu.g2.resize(ahu.n);
    for (int i = 1, u, v; i < ahu.n; ++i) {
      cin >> u >> v; --u; --v;
      ahu.g1[u].emb(v);
      ahu.g1[v].emb(u);
    }
    for (int i = 1, u, v; i < ahu.n; ++i) {
      cin >> u >> v; --u; --v;
      ahu.g2[u].emb(v);
      ahu.g2[v].emb(u);
    }
    cout << (ahu.check() ? "YES\n" : "NO\n");
  }
  return 0;
}
