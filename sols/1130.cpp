#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, f[N][2];
vector<int> adj[N];

void dfs(int u, int p) {
  for (int v: adj[u]) {
    if (v == p) continue;
    dfs(v, u);
    f[u][0] += max(f[v][0], f[v][1]);
  }
  for (int v: adj[u]) {
    if (v == p) continue;
    f[u][1] = max(f[u][1], 1 + f[v][0] + f[u][0] - max(f[v][0], f[v][1]));
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
  dfs(1, -1);
  cout << max(f[1][0], f[1][1]) << "\n";
  return 0;
}
