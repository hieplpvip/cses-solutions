#include <bits/stdc++.h>
using namespace std;
const int N = 505;

int n, m, lev[N], c[N][N], seen[N];
queue<int> q;

bool bfs() {
  fill(lev + 1, lev + 1 + n, -1);
  lev[1] = 0;
  q.emplace(1);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v = 1; v <= n; ++v) {
      if (lev[v] == -1 && c[u][v]) {
        lev[v] = lev[u] + 1;
        q.emplace(v);
      }
    }
  }
  return (lev[n] != -1);
}

bool dfs(int u) {
  if (u == n) return true;
  for (int &v = seen[u]; v <= n; ++v) {
    if (lev[v] == lev[u] + 1 && c[u][v] && dfs(v)) {
      --c[u][v];
      ++c[v][u];
      return true;
    }
  }
  return false;
}

void dfs2(int u) {
  lev[u] = 1;
  for (int v = 1; v <= n; ++v) {
    if (!lev[v] && c[u][v]) dfs2(v);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for (int u, v; m--;) {
    cin >> u >> v;
    ++c[u][v]; ++c[v][u];
  }
  while (bfs()) {
    fill(seen + 1, seen + 1 + n, 1);
    while (dfs(1));
  }
  fill(lev + 1, lev + 1 + n, 0);
  dfs2(1);
  vector<pair<int, int>> rem;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (lev[i] && !lev[j] && c[j][i]) {
        rem.emplace_back(i, j);
      }
    }
  }
  cout << rem.size() << "\n";
  for (auto [u, v]: rem) {
    cout << u << " " << v << "\n";
  }
  return 0;
}
