#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, t[N], m, cmp[N], clen[N], r[N], dis[N];
vector<int> rg[N];
bool isroot[N];

void dfs(int u, int root) {
  if (isroot[u]) root = u;
  r[u] = root;
  cmp[u] = m;
  for (int v: rg[u]) {
    if (!cmp[v]) {
      dis[v] = dis[u] + 1;
      dfs(v, root);
    }
  }
}

void process(int s) {
  ++m;
  int x = t[s], y = t[t[s]];
  while (x != y) {
    x = t[x];
    y = t[t[y]];
  }
  x = s;
  while (x != y) {
    x = t[x];
    y = t[y];
  }
  do {
    isroot[y] = true;
    ++clen[m];
    y = t[y];
  } while (y != x);
  dfs(x, -1);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> t[i];
    rg[t[i]].emplace_back(i);
  }
  for (int i = 1; i <= n; ++i) {
    if (!cmp[i]) process(i);
    cout << dis[i] - dis[r[i]] + clen[cmp[i]] << " \n"[i == n];
  }
  return 0;
}
