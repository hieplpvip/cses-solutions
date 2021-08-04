#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;

int n, m;
ll dist[N];
priority_queue<pair<ll, int>> q;
vector<pair<int, int>> g[N];

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for (int i = 1, u, v, w; i <= m; ++i) {
    cin >> u >> v >> w;
    g[u].emplace_back(v, w);
  }
  fill(dist + 1, dist + 1 + n, 1e18);
  q.emplace(dist[1] = 0, 1);
  while (!q.empty()) {
    auto [du, u] = q.top(); q.pop();
    du = -du;
    if (du != dist[u]) continue;
    for (auto [v, w]: g[u]) {
      if (dist[v] > du + w) {
        dist[v] = du + w;
        q.emplace(-dist[v], v);
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << dist[i] << " \n"[i == n];
  }
  return 0;
}
