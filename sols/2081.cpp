#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, k1, k2;
long long ans;
deque<int> d[N];
vector<int> g[N];

int get(deque<int> &a, int x, int y) {
  x = max(x, 0);
  y = min(y + 1, (int)a.size());
  if (x >= y) return 0;
  if (y < (int)a.size()) return a[x] - a[y];
  else return a[x];
}

void combine(deque<int> &a, deque<int> &b) {
  if (a.size() < b.size()) a.swap(b);
  for (int i = 0; i < (int)b.size(); ++i) {
    ans += 1LL * get(b, i, i) * get(a, k1 - i, k2 - i);
  }
  for (int i = 0; i < (int)b.size(); ++i) {
    a[i] += b[i];
  }
}

void dfs(int u, int p) {
  d[u] = {1};
  for (int v: g[u]) {
    if (v == p) continue;
    dfs(v, u);
    d[v].emplace_front(d[v].front());
    combine(d[u], d[v]);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> k1 >> k2;
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  dfs(1, -1);
  cout << ans;
  return 0;
}
