#include <bits/stdc++.h>
using namespace std;
const int N = 105;

int n, matchl[N], matchr[N], d[N];
bool markl[N], markr[N];
vector<int> g[N], row, col;
queue<int> q;

bool bfs() {
  for (int i = 1; i <= n; ++i) {
    if (!matchl[i]) {
      d[i] = 0;
      q.emplace(i);
    } else {
      d[i] = -1;
    }
  }
  d[0] = -1;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v: g[u]) {
      if (d[matchr[v]] == -1) {
        d[matchr[v]] = d[u] + 1;
        q.emplace(matchr[v]);
      }
    }
  }
  return (d[0] != -1);
}

bool dfs(int u) {
  if (u == 0) return true;
  for (int v: g[u]) {
    if (d[matchr[v]] == d[u] + 1 && dfs(matchr[v])) {
      matchl[u] = v;
      matchr[v] = u;
      return true;
    }
  }
  return false;
}

void mark(int u) {
  markl[u] = true;
  for (int v: g[u]) {
    if (!markr[v]) {
      markr[v] = true;
      if (matchr[v]) {
        mark(matchr[v]);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      char c; cin >> c;
      if (c == 'o') {
        g[i].emplace_back(j);
      }
    }
  }
  while (bfs()) {
    for (int i = 1; i <= n; ++i) {
      if (!matchl[i]) {
        dfs(i);
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!matchl[i] && !markl[i]) {
      mark(i);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!markl[i]) {
      row.emplace_back(i);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (markr[i]) {
      col.emplace_back(i);
    }
  }
  cout << row.size() + col.size() << "\n";
  for (int r: row) {
    cout << "1 " << r << "\n";
  }
  for (int c: col) {
    cout << "2 " << c << "\n";
  }
  return 0;
}
