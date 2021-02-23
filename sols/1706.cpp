#pragma GCC target("popcnt")
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, m, par[N];
bitset<N> f;

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
  while (m--) {
    int u, v;
    cin >> u >> v;
    join(u, v);
  }
  f.set(0);
  for (int i = 1; i <= n; ++i) {
    if (par[i] < 0) {
      f |= f << (-par[i]);
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << f[i];
  }
  return 0;
}
