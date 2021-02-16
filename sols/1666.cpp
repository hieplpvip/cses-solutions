#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, m, par[N];
vector<int> adj[N];

int root(int v) {
  return (par[v] < 0) ? v : (par[v] = root(par[v]));
}

void join(int x, int y) {
  if ((x = root(x)) == (y = root(y))) return;
  if (par[x] > par[y]) swap(x, y);
  par[x] += par[y];
  par[y] = x;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  fill(par + 1, par + 1 + n, -1);
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    join(u, v);
  }
  vector<int> root;
  for (int i = 1; i <= n; ++i) {
    if (par[i] < 0) {
      root.emplace_back(i);
    }
  }
  cout << (int)root.size() - 1 << "\n";
  for (size_t i = 1; i < root.size(); ++i) {
    cout << root[i - 1] << " " << root[i] << "\n";
  }
  return 0;
}
