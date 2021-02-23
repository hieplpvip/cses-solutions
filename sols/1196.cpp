#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;

int n, m, k;
ll dist[N][10];
vector<pair<int, int>> g[N];
priority_queue<pair<ll, int>> q;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 1, u, v, w; i <= m; ++i) {
    cin >> u >> v >> w;
    g[u].emplace_back(v, w);
  }
  memset(dist, 0x6f, sizeof(dist));
  q.emplace(dist[1][0] = 0, 1);
  while (!q.empty()) {
    auto [du, u] = q.top(); q.pop();
    du = -du;
    if (du > dist[u][k - 1]) continue;
    for (auto [v, w]: g[u]) {
      ll dv = du + w;
      if (dv < dist[v][k - 1]) {
        for (int i = k - 1; i >= 0; --i) {
          if (i > 0 && dv < dist[v][i - 1]) {
            dist[v][i] = dist[v][i - 1];
          } else {
            dist[v][i] = dv;
            break;
          }
        }
        q.emplace(-dv, v);
      }
    }
  }
  for (int i = 0; i < k; ++i) {
    cout << dist[n][i] << " \n"[i == k - 1];
  }
  return 0;
}
