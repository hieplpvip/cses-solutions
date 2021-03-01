#include <bits/stdc++.h>
using namespace std;
const int N = 2505;

int n, m, p[N];
long long dist[N];
vector<tuple<int, int, int>> edges;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for (int u, v, c; m--;) {
    cin >> u >> v >> c;
    edges.emplace_back(u, v, c);
  }
  fill(dist + 1, dist + 1 + n, 1e18);
  dist[1] = 0;
  int x = -1;
  for (int i = 0; i < n; ++i) {
    x = -1;
    for (auto [u, v, c]: edges) {
      if (dist[v] > dist[u] + c) {
        dist[v] = dist[u] + c;
        p[v] = u;
        x = v;
      }
    }
  }
  if (x == -1) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
      x = p[x];
    }
    vector<int> path;
    do {
      path.emplace_back(x);
      x = p[x];
    } while (path.size() < 2 || path.back() != path[0]);
    reverse(path.begin(), path.end());
    for (int u: path) {
      cout << u << " ";
    }
  }
  return 0;
}
