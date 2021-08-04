#include <bits/stdc++.h>
using namespace std;
const int N = 2505;

int n, m;
long long dist[N];
bool vis1[N], vis2[N];
vector<int> changed;
vector<pair<int, int>> g[N], revg[N];

void dfs1(int u) {
  vis1[u] = true;
  for (auto p: g[u]) {
    if (!vis1[p.first]) {
      dfs1(p.first);
    }
  }
}

void dfs2(int u) {
  vis2[u] = true;
  for (auto p: revg[u]) {
    if (!vis2[p.first]) {
      dfs2(p.first);
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for (int a, b, x; m--;) {
    cin >> a >> b >> x;
    g[a].emplace_back(b, x);
    revg[b].emplace_back(a, x);
  }
  fill(dist + 1, dist + 1 + n, -1e15);
  dist[1] = 0;
  for (int i = 0; i < n; ++i) {
    changed.clear();
    for (int u = 1; u <= n; ++u) {
      for (auto [v, c]: g[u]) {
        if (dist[v] < dist[u] + c) {
          dist[v] = dist[u] + c;
          changed.emplace_back(v);
        }
      }
    }
  }
  if (!changed.empty()) {
    dfs1(1); dfs2(n);
    for (int u: changed) {
      if (vis1[u] && vis2[u]) {
        cout << "-1";
        return 0;
      }
    }
  }
  cout << dist[n];
  return 0;
}
