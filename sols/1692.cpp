#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  if (n == 1) {
    cout << "01";
    return 0;
  }
  int m = 1 << (n - 1);
  vector<vector<int>> g(m, vector<int>());
  for (int i = 0; i < m; ++i) {
    g[i].emplace_back((i << 1) & (m - 1));
    g[i].emplace_back(((i << 1) & (m - 1)) | 1);
  }
  vector<int> a, s;
  s.emplace_back(0);
  while (!s.empty()) {
    int u = s.back();
    while (!g[u].empty()) {
      s.emplace_back(g[u].back());
      g[u].pop_back();
      u = s.back();
    }
    a.emplace_back(u);
    s.pop_back();
  }
  reverse(a.begin(), a.end());
  for (int i = 1; i <= n - 2; ++i) {
    cout << 0;
  }
  for (int i: a) {
    cout << (i & 1);
  }
  return 0;
}
