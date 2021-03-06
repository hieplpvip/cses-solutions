#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, k;
long long ans;
deque<int> d[N];
vector<int> g[N];

int get(deque<int> &a, int x) {
  if (x < 0 || x >= (int)a.size()) return 0;
  if (x + 1 < (int)a.size()) return a[x] - a[x + 1];
  else return a[x];
}

void combine(deque<int> &a, deque<int> &b) {
  if (a.size() < b.size()) a.swap(b);
  for (int i = 0; i < (int)b.size(); ++i) {
    ans += 1LL * get(b, i) * get(a, k - i);
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
  cin >> n >> k;
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  dfs(1, -1);
  cout << ans;
  return 0;
}
