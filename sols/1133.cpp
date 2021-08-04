#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, sz[N];
long long ans[N];
vector<int> adj[N];

void dfs1(int u, int p) {
  sz[u] = 1;
  ans[u] = 0;
  for (int v: adj[u]) {
    if (v == p) continue;
    dfs1(v, u);
    sz[u] += sz[v];
    ans[u] += ans[v] + sz[v];
  }
}

void dfs2(int u, int p, long long val) {
  ans[u] = val;
  for (int v: adj[u]) {
    if (v == p) continue;
    dfs2(v, u, val - sz[v] + n - sz[v]);
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
  dfs1(1, -1);
  dfs2(1, -1, ans[1]);
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " \n"[i == n];
  }
  return 0;
}
