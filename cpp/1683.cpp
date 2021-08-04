#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, m, k, par[N], Time, num[N], low[N], cmp[N];
vector<int> g[N], s;

int tarjan(int u) {
  num[u] = low[u] = ++Time;
  s.emplace_back(u);
  for (int v: g[u]) {
    if (!cmp[v]) {
      low[u] = min(low[u], num[v] ?: tarjan(v));
    }
  }
  if (low[u] == num[u]) {
    int v; ++k;
    do {
      v = s.back(); s.pop_back();
      cmp[v] = k;
    } while (v != u);
  }
  return low[u];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    g[u].emplace_back(v);
  }
  for (int i = 1; i <= n; ++i) {
    if (!num[i]) tarjan(i);
  }
  cout << k << "\n";
  for (int i = 1; i <= n; ++i) {
    cout << cmp[i] << " \n"[i == n];
  }
  return 0;
}
