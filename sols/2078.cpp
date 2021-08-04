#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, MOD = 1e9 + 7;

int n, m, par[N];

int root(int v) {
  return (par[v] < 0) ? v : (par[v] = root(par[v]));
}

void join(int x, int y) {
  if ((x = root(x)) == (y = root(y))) return;
  if (par[x] > par[y]) swap(x, y);
  par[x] += par[y];
  par[y] = x;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  fill(par + 1, par + 1 + n, -1);
  int ans = 1;
  for (int u, v; m--;) {
    cin >> u >> v;
    if (root(u) != root(v)) {
      join(u, v);
    } else {
      ans *= 2;
      if (ans >= MOD) ans -= MOD;
    }
  }
  cout << ans;
  return 0;
}
