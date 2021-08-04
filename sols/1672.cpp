#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, q;
ll d[505][505];

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m >> q;
  fill(&d[0][0], &d[0][0] + sizeof(d) / sizeof(ll), 1e18);
  for (int i = 1; i <= n; ++i) {
    d[i][i] = 0;
  }
  for (int i = 1, u, v, c; i <= m; ++i) {
    cin >> u >> v >> c;
    d[u][v] = d[v][u] = min(d[u][v], (ll)c);
  }
  for (int k = 1; k <= n; ++k) {
    for (int u = 1; u <= n; ++u) {
      for (int v = 1; v <= n; ++v) {
        d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
      }
    }
  }
  while (q--) {
    int u, v; cin >> u >> v;
    if (d[u][v] == 1e18) d[u][v] = -1;
    cout << d[u][v] << "\n";
  }
  return 0;
}
