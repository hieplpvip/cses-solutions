#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, f[N];
vector<int> adj[N];

void dfs(int u) {
  f[u] = 1;
  for (int v: adj[u]) {
    dfs(v);
    f[u] += f[v];
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 2, p; i <= n; ++i) {
    cin >> p;
    adj[p].emplace_back(i);
  }
  dfs(1);
  for (int i = 1; i <= n; ++i) {
    cout << f[i] - 1 << " \n"[i == n];
  }
  return 0;
}
