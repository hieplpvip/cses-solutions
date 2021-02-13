#include <bits/stdc++.h>
using namespace std;
const int N = 1005;

int n, m, k;
bool vis[N];
unordered_multiset<int> adj[N];
vector<int> ans[N];

bool dfs(int u) {
  if (u == n) {
    ++k;
    ans[k].emplace_back(u);
    return true;
  }
  vis[u] = true;
  for (int v: adj[u]) {
    if (!vis[v] && dfs(v)) {
      adj[u].erase(adj[u].find(v));
      ans[k].emplace_back(u);
      return true;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    adj[u].emplace(v);
  }
  while (true) {
    fill(vis + 1, vis + 1 + n, false);
    if (!dfs(1)) break;
  }
  cout << k << "\n";
  for (int i = 1; i <= k; ++i) {
    reverse(ans[i].begin(), ans[i].end());
    cout << ans[i].size() << "\n";
    for (int u: ans[i]) cout << u << " ";
    cout << "\n";
  }
  return 0;
}
