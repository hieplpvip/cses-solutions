#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, m, par[N];
vector<tuple<int, int, int>> edges;

int root(int v) {
  return (par[v] < 0) ? v : (par[v] = root(par[v]));
}

bool join(int x, int y) {
  if ((x = root(x)) == (y = root(y))) return false;
  if (par[x] > par[y]) swap(x, y);
  par[x] += par[y];
  par[y] = x;
  return true;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for (int i = 1, u, v, w; i <= m; ++i) {
    cin >> u >> v >> w;
    edges.emplace_back(w, u, v);
  }
  sort(edges.begin(), edges.end());
  fill(par + 1, par + 1 + n, -1);
  long long ans = 0;
  for (auto [w, u, v]: edges) {
    if (join(u, v)) {
      ans += w;
    }
  }
  if (par[root(1)] != -n) {
    cout << "IMPOSSIBLE\n";
  } else {
    cout << ans << "\n";
  }
  return 0;
}
