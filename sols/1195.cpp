#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;

int n, m;
ll dist[N][2];
vector<pair<int, int>> g[N];
priority_queue<tuple<ll, int, int>> q;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for (int u, v, c; m--;) {
    cin >> u >> v >> c;
    g[u].emplace_back(v, c);
  }
  memset(dist, 0x6f, sizeof(dist));
  q.emplace(dist[1][0] = 0, 1, 0);
  while (!q.empty()) {
    auto [du, u, t] = q.top(); q.pop();
    du = -du;
    if (du != dist[u][t]) continue;
    for (auto [v, c]: g[u]) {
      if (!t) {
        if (dist[v][0] > du + c) {
          dist[v][0] = du + c;
          q.emplace(-dist[v][0], v, 0);
        }
        if (dist[v][1] > du + c / 2) {
          dist[v][1] = du + c / 2;
          q.emplace(-dist[v][1], v, 1);
        }
      } else {
        if (dist[v][1] > du + c) {
          dist[v][1] = du + c;
          q.emplace(-dist[v][1], v, 1);
        }
      }
    }
  }
  cout << dist[n][1];
  return 0;
}
