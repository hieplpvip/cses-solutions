#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, m, Time, num[N];
vector<int> g[N];
vector<pair<int, int>> edges;

void dfs(int u) {
  num[u] = ++Time;
  for (int v: g[u]) {
    if (!num[v]) dfs(v);
    if (num[u] < num[v]) {
      edges.emplace_back(u, v);
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for (int u, v; m--;) {
    cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  for (int i = 1; i <= n; ++i) {
    if (!num[i]) dfs(i);
  }
  for (auto [u, v]: edges) {
    cout << u << " " << v << "\n";
  }
  return 0;
}
