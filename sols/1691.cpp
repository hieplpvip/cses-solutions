#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, m, deg[N];
vector<pair<int, int>> g[N];
vector<int> euler;
stack<int> s;
bool rem[N];

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    g[u].emplace_back(v, i);
    g[v].emplace_back(u, i);
    ++deg[u]; ++deg[v];
  }
  for (int i = 1; i <= n; ++i) {
    if (deg[i] & 1) {
      cout << "IMPOSSIBLE\n";
      return 0;
    }
  }
  s.emplace(1);
  while (!s.empty()) {
    int u = s.top();
    while (!g[u].empty()) {
      auto [v, id] = g[u].back();
      g[u].pop_back();
      if (rem[id]) continue;
      rem[id] = true;
      s.emplace(v);
      u = v;
    }
    euler.emplace_back(s.top());
    s.pop();
  }
  if ((int)euler.size() != m + 1) {
    cout << "IMPOSSIBLE\n";
  } else {
    for (int u: euler) {
      cout << u << " ";
    }
  }
  return 0;
}
