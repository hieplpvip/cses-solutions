#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, m, indeg[N], outdeg[N];
vector<int> g[N], euler;
stack<int> s;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    g[u].emplace_back(v);
    ++outdeg[u];
    ++indeg[v];
  }
  if (outdeg[1] != indeg[1] + 1 || indeg[n] != outdeg[n] + 1) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  for (int i = 2; i < n; ++i) {
    if (indeg[i] != outdeg[i]) {
      cout << "IMPOSSIBLE\n";
      return 0;
    }
  }
  s.emplace(1);
  while (!s.empty()) {
    int u = s.top();
    while (!g[u].empty()) {
      s.emplace(g[u].back());
      g[u].pop_back();
      u = s.top();
    }
    euler.emplace_back(s.top());
    s.pop();
  }
  if ((int)euler.size() != m + 1) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  reverse(euler.begin(), euler.end());
  for (int u: euler) {
    cout << u << " ";
  }
  return 0;
}
