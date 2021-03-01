#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, m, q, par[N], ea[N], eb[N], qa[N], qb[N], l[N], r[N], ans[N];
vector<int> check[N];

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
  cin >> n >> m >> q;
  for (int i = 1; i <= m; ++i) {
    cin >> ea[i] >> eb[i];
  }
  for (int i = 1; i <= q; ++i) {
    cin >> qa[i] >> qb[i];
    if (qa[i] == qb[i]) {
      r[i] = -1;
      ans[i] = 0;
    } else {
      l[i] = 1;
      r[i] = m;
      ans[i] = -1;
    }
  }
  while (true) {
    bool f = false;
    for (int i = 1; i <= q; ++i) {
      if (l[i] <= r[i]) {
        f = true;
        check[(l[i] + r[i]) >> 1].emplace_back(i);
      }
    }
    if (!f) break;
    fill(par + 1, par + 1 + n, -1);
    for (int i = 1; i <= m; ++i) {
      join(ea[i], eb[i]);
      for (int j: check[i]) {
        if (root(qa[j]) == root(qb[j])) {
          ans[j] = i;
          r[j] = i - 1;
        } else {
          l[j] = i + 1;
        }
      }
      check[i].clear();
    }
  }
  for (int i = 1; i <= q; ++i) {
    cout << ans[i] << "\n";
  }
  return 0;
}
