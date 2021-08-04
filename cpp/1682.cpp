#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, nn, m, par[N], Time, num[N], low[N], cmp[N];
vector<int> g[N], s, root;
bool reach[N];

int tarjan(int u) {
  num[u] = low[u] = ++Time;
  s.emplace_back(u);
  for (int v: g[u]) {
    if (!cmp[v]) {
      low[u] = min(low[u], num[v] ?: tarjan(v));
    }
  }
  if (low[u] == num[u]) {
    int v; ++nn;
    root.emplace_back(u);
    do {
      v = s.back(); s.pop_back();
      cmp[v] = nn;
    } while (v != u);
  }
  return low[u];
}

void dfs(int u) {
  reach[u] = true;
  for (int v: g[u]) {
    if (!reach[v]) {
      dfs(v);
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    g[u].emplace_back(v);
  }
  for (int i = 1; i <= n; ++i) {
    if (!num[i]) tarjan(i);
  }
  if (root.size() == 1) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
    dfs(root[0]);
    if (!reach[root[1]]) {
      cout << root[0] << " " << root[1] << "\n";
    } else {
      cout << root[1] << " " << root[0] << "\n";
    }
  }
  return 0;
}
