#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, q, t[N];
int m, cmp[N], clen[N], r[N], Time, in[N], out[N], dis[N];
bool isroot[N];
vector<int> rg[N];

void dfs(int u, int root) {
  if (isroot[u]) root = u;
  r[u] = root;
  in[u] = ++Time;
  cmp[u] = m;
  for (int v: rg[u]) {
    if (!in[v]) {
      dis[v] = dis[u] + 1;
      dfs(v, root);
    }
  }
  out[u] = Time;
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
    y = t[y];
    ++clen[m];
  } while (y != x);
  dfs(x, -1);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> t[i];
    rg[t[i]].emplace_back(i);
  }
  for (int i = 1; i <= n; ++i) {
    if (!cmp[i]) {
      process(i);
    }
  }
  while (q--) {
    int a, b; cin >> a >> b;
    if (cmp[a] != cmp[b]) {
      cout << "-1\n";
      continue;
    }
    if (isroot[b]) {
      int ans = dis[a] - dis[r[a]];
      a = r[a];
      if (a != b) {
        if (dis[b] < dis[a]) {
          ans += dis[a] - dis[b];
        } else {
          ans += clen[cmp[a]] + dis[a] - dis[b];
        }
      }
      cout << ans << "\n";
    } else if (r[a] == r[b] && in[b] <= in[a] && out[a] <= out[b]) {
      cout << dis[a] - dis[b] << "\n";
    } else {
      cout << "-1\n";
    }
  }
  return 0;
}
