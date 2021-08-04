#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int n, m, f[1 << 20][20];
vector<int> g[20];

int main() {
  cin >> n >> m;
  for (int u, v; m--;) {
    cin >> u >> v;
    --u; --v;
    g[v].emplace_back(u);
  }
  f[1][0] = 1;
  for (int mk = 3; mk < (1 << n); mk += 2) {
    for (int i = 0; i < n; ++i) {
      if (((mk >> i) & 1) == 0) continue;
      for (int j: g[i]) {
        if (((mk >> j) & 1) == 0) continue;
        f[mk][i] += f[mk ^ (1 << i)][j];
        if (f[mk][i] >= MOD) f[mk][i] -= MOD;
      }
    }
  }
  cout << f[(1 << n) - 1][n - 1];
  return 0;
}
