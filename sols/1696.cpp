#include <bits/stdc++.h>
using namespace std;
const int N = 505, INF = 1e9;

int n, m, k, d[N], matchl[N], matchr[N];
vector<int> g[N];
queue<int> q;

bool bfs() {
  d[0] = INF;
  for (int i = 1; i <= n; ++i) {
    if (!matchl[i]) {
      d[i] = 0;
      q.emplace(i);
    } else {
      d[i] = INF;
    }
  }
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v: g[u]) {
      if (d[matchr[v]] == INF) {
        d[matchr[v]] = d[u] + 1;
        q.emplace(matchr[v]);
      }
    }
  }
  return (d[0] != INF);
}

bool dfs(int u) {
  if (!u) return true;
  for (int v: g[u]) {
    if (d[matchr[v]] == d[u] + 1 && dfs(matchr[v])) {
      matchl[u] = v;
      matchr[v] = u;
      return true;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m >> k;
  n = max(n, m);
  for (int u, v; k--;) {
    cin >> u >> v;
    g[u].emplace_back(v);
  }
  int res = 0;
  while (bfs()) {
    for (int i = 1; i <= n; ++i) {
      if (!matchl[i] && dfs(i)) {
        ++res;
      }
    }
  }
  cout << res << "\n";
  for (int i = 1; i <= n; ++i) {
    if (matchl[i]) {
      cout << i << " " << matchl[i] << "\n";
    }
  }
  return 0;
}
