#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, d[N], x;
vector<int> adj[N];

void dfs(int u, int p) {
  if (d[u] > d[x]) x = u;
  for (int v: adj[u]) {
    if (v != p) {
      d[v] = d[u] + 1;
      dfs(v, u);
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  d[1] = 0; dfs(1, -1);
  d[x] = 0; dfs(x, -1);
  cout << d[x] << "\n";
  return 0;
}
