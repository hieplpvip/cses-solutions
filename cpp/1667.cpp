#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, m, dist[N], pre[N];
vector<int> adj[N];
queue<int> q;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  fill(dist + 1, dist + 1 + n, -1);
  dist[1] = 0;
  q.emplace(1);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v: adj[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        pre[v] = u;
        q.emplace(v);
      }
    }
  }
  if (dist[n] == -1) {
    cout << "IMPOSSIBLE\n";
  } else {
    vector<int> vert;
    for (int u = n; u; u = pre[u]) {
      vert.emplace_back(u);
    }
    reverse(vert.begin(), vert.end());
    cout << vert.size() << "\n";
    for (int u: vert) cout << u << " ";
    cout << "\n";
  }
  return 0;
}
