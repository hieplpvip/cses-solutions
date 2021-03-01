#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, m, Time, num[N], low[N], comp[N], val[N];
vector<int> g[N], s;

void either(int x, int y) {
  g[x ^ 1].emplace_back(y);
  g[y ^ 1].emplace_back(x);
}

int dfs(int u) {
  num[u] = low[u] = ++Time;
  s.emplace_back(u);
  for (int v: g[u]) {
    if (!comp[v]) {
      low[u] = min(low[u], num[v] ?: dfs(v));
    }
  }
  if (low[u] == num[u]) {
    int v;
    do {
      v = s.back(); s.pop_back();
      comp[v] = u + 1;
      if (val[v >> 1] == -1) {
        val[v >> 1] = !(v & 1);
      }
    } while (v != u);
  }
  return low[u];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> m >> n;
  while (m--) {
    char t1, t2;
    int x1, x2;
    cin >> t1 >> x1 >> t2 >> x2;
    x1 = 2 * (x1 - 1) + (t1 == '-');
    x2 = 2 * (x2 - 1) + (t2 == '-');
    either(x1, x2);
  }
  fill(val, val + 2 * n, -1);
  for (int i = 0; i < 2 * n; ++i) {
    if (!comp[i]) dfs(i);
  }
  for (int i = 0; i < n; ++i) {
    if (comp[2 * i] == comp[2 * i + 1]) {
      cout << "IMPOSSIBLE";
      return 0;
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << (val[i] ? '+' : '-');
  }
  return 0;
}
