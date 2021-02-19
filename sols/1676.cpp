#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, m, par[N], mxcmp;

int root(int v) {
  return (par[v] < 0) ? v : (par[v] = root(par[v]));
}

bool join(int x, int y) {
  if ((x = root(x)) == (y = root(y))) return false;
  if (par[x] > par[y]) swap(x, y);
  par[x] += par[y];
  par[y] = x;
  mxcmp = max(mxcmp, -par[x]);
  return true;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  fill(par + 1, par + 1 + n, -1);
  for (int i = 1, u, v, cnt = n; i <= m; ++i) {
    cin >> u >> v;
    if (join(u, v)) --cnt;
    cout << cnt << " " << mxcmp << "\n";
  }
  return 0;
}
