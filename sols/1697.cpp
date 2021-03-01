#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  vector<int> deg(n), tmp;
  vector<pair<int, int>> edges;
  priority_queue<pair<int, int>> q;
  for (int i = 0; i < n; ++i) {
    cin >> deg[i];
    if (deg[i]) q.emplace(deg[i], i);
  }
  while (!q.empty()) {
    auto [degu, u] = q.top(); q.pop();
    tmp.clear();
    while (degu--) {
      if (q.empty()) {
        cout << "IMPOSSIBLE\n";
        return 0;
      }
      int v = q.top().second; q.pop();
      edges.emplace_back(u + 1, v + 1);
      if (--deg[v] > 0) {
        tmp.emplace_back(v);
      }
    }
    for (int v: tmp) {
      q.emplace(deg[v], v);
    }
  }
  cout << edges.size() << "\n";
  for (auto [u, v]: edges) {
    cout << u << " " << v << "\n";
  }
  return 0;
}
