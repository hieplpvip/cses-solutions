#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, m, mark[N];
vector<int> g[N], order;
bool cycle;

void dfs(int u) {
  mark[u] = 1;
  for (int v: g[u]) {
    if (!mark[v]) {
      dfs(v);
    } else if (mark[v] == 1) {
      cycle = true;
      return;
    }
  }
  order.emplace_back(u);
  mark[u] = 2;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    g[v].emplace_back(u);
  }
  for (int i = 1; i <= n; ++i) {
    if (!mark[i]) {
      dfs(i);
    }
  }
  if (cycle) {
    cout << "IMPOSSIBLE\n";
  } else {
    for (int u: order) {
      cout << u << " ";
    }
  }
  return 0;
}
