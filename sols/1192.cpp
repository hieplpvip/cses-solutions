#include <bits/stdc++.h>
#define conv(i, j) ((i - 1) * m + j)
using namespace std;
const int N = 1005;

int n, m, par[N * N], cnt;
char mat[N][N];

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
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> mat[i][j];
      if (mat[i][j] == '.') ++cnt;
      par[conv(i, j)] = -1;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (mat[i][j] == '.') {
        if (i < n && mat[i + 1][j] == '.') {
          if (join(conv(i, j), conv(i + 1, j))) --cnt;
        }
        if (j < m && mat[i][j + 1] == '.') {
          if (join(conv(i, j), conv(i, j + 1))) --cnt;
        }
      }
    }
  }
  cout << cnt << "\n";
  return 0;
}
