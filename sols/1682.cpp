#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, m, par[N], num[N], low[N], Time;
bool reach[N];
vector<int> g[N];
stack<int> s;

int root(int v) {
  return (par[v] < 0) ? v : (par[v] = root(par[v]));
}

void join(int x, int y) {
  if ((x = root(x)) == (y = root(y))) return;
  if (par[x] > par[y]) swap(x, y);
  par[x] += par[y];
  par[y] = x;
}

void dfs(int u) {
  num[u] = low[u] = ++Time;
  s.emplace(u);
  for (int v: g[u]) {
    if (num[v]) {
      low[u] = min(low[u], num[v]);
    } else {
      dfs(v);
      low[u] = min(low[u], low[v]);
    }
  }
  if (low[u] == num[u]) {
    int v;
    do {
      v = s.top(); s.pop();
      num[v] = low[v] = 1e9;
      join(u, v);
    } while (v != u);
  }
}

void dfs2(int u) {
  reach[u] = true;
  for (int v: g[u]) {
    if (!reach[v]) {
      dfs2(v);
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
  fill(par + 1, par + 1 + n, -1);
  for (int i = 1; i <= n; ++i) {
    if (!num[i]) dfs(i);
  }
  vector<int> root;
  for (int i = 1; i <= n; ++i) {
    if (par[i] < 0) {
      root.emplace_back(i);
    }
  }
  if (root.size() == 1) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
    dfs2(root[0]);
    if (!reach[root[1]]) {
      cout << root[0] << " " << root[1] << "\n";
    } else {
      cout << root[1] << " " << root[0] << "\n";
    }
  }
  return 0;
}
