#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5, MOD = 1e9 + 7;

int n, m, cnt[N], minnum[N], maxnum[N];
ll dist[N];
vector<int> order;
vector<pair<int, int>> g[N];
priority_queue<pair<ll, int>> q;

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
    order.emplace_back(u);
    for (auto [v, w]: g[u]) {
      if (dist[v] > du + w) {
        dist[v] = du + w;
        q.emplace(-dist[v], v);
      }
    }
  }
  reverse(order.begin(), order.end());
  for (int u: order) {
    if (u == n) {
      cnt[u] = 1;
      minnum[u] = maxnum[u] = 0;
    } else {
      cnt[u] = 0;
      minnum[u] = +1e9;
      maxnum[u] = -1e9;
    }
    for (auto [v, w]: g[u]) {
      if (dist[v] == dist[u] + w) {
        cnt[u] += cnt[v];
        minnum[u] = min(minnum[u], minnum[v] + 1);
        maxnum[u] = max(maxnum[u], maxnum[v] + 1);
        if (cnt[u] >= MOD) {
          cnt[u] -= MOD;
        }
      }
    }
  }
  cout << dist[n] << " " << cnt[1] << " " << minnum[1] << " " << maxnum[1] << "\n";
  return 0;
}
