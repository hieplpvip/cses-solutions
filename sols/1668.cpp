#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, m, col[N];
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
  for (int i = 1; i <= n; ++i) {
    if (col[i]) continue;
    col[i] = 1;
    q.emplace(i);
    while (!q.empty()) {
      int u = q.front(); q.pop();
      for (int v: adj[u]) {
        if (col[v] == 0) {
          col[v] = 3 - col[u];
          q.emplace(v);
        } else if (col[v] == col[u]) {
          cout << "IMPOSSIBLE\n";
          return 0;
        }
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << col[i] << " \n"[i == n];
  }
  return 0;
}
