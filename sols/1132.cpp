#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, mx1[N], mx2[N], id1[N], id2[N];
vector<int> adj[N];

void dfs1(int u, int p) {
  mx1[u] = 0;
  mx2[u] = -1e9;
  for (int v: adj[u]) {
    if (v == p) continue;
    dfs1(v, u);
    int x = mx1[v] + 1;
    if (x > mx1[u]) {
      mx2[u] = mx1[u]; id2[u] = id1[u];
      mx1[u] = x; id1[u] = v;
    } else if (x > mx2[u]) {
      mx2[u] = x; id2[u] = v;
    }
  }
}

void dfs2(int u, int p) {
  if (p != -1) {
    int x = (u != id1[p]) ? (mx1[p] + 1) : (mx2[p] + 1);
    if (x > mx1[u]) {
      mx2[u] = mx1[u]; id2[u] = id1[u];
      mx1[u] = x; id1[u] = p;
    } else if (x > mx2[u]) {
      mx2[u] = x; id2[u] = p;
    }
  }
  for (int v: adj[u]) {
    if (v != p) dfs2(v, u);
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
  dfs2(1, -1);
  for (int i = 1; i <= n; ++i) {
    cout << mx1[i] << " \n"[i == n];
  }
  return 0;
}
