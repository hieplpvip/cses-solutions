#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
const int N = 1005;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
const char dc[] = {'L', 'R', 'U', 'D'};

int n, m, xs, ys, xe = -1, ye, md[N][N], ad[N][N];
char mat[N][N], prec[N][N];
ii pre[N][N];
queue<ii> q;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  memset(md, -1, sizeof(md));
  memset(ad, -1, sizeof(ad));
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> mat[i][j];
      if (mat[i][j] == 'A') {
        xs = i;
        ys = j;
      } else if (mat[i][j] == 'M') {
        md[i][j] = 0;
        q.emplace(i, j);
      }
    }
  }
  while (!q.empty()) {
    auto [x, y] = q.front(); q.pop();
    for (int k = 0; k < 4; ++k) {
      int xx = x + dx[k], yy = y + dy[k];
      if (1 <= xx && xx <= n && 1 <= yy && yy <= m && mat[xx][yy] != '#' && md[xx][yy] == -1) {
        md[xx][yy] = md[x][y] + 1;
        q.emplace(xx, yy);
      }
    }
  }
  ad[xs][ys] = 0;
  q.emplace(xs, ys);
  while (!q.empty()) {
    auto [x, y] = q.front(); q.pop();
    if (x == 1 || x == n || y == 1 || y == m) {
      xe = x;
      ye = y;
      break;
    }
    for (int k = 0; k < 4; ++k) {
      int xx = x + dx[k], yy = y + dy[k];
      if (1 <= xx && xx <= n && 1 <= yy && yy <= m && mat[xx][yy] != '#' && ad[xx][yy] == -1 && (md[xx][yy] == -1 || md[xx][yy] > ad[x][y] + 1)) {
        ad[xx][yy] = ad[x][y] + 1;
        pre[xx][yy] = {x, y};
        prec[xx][yy] = dc[k];
        q.emplace(xx, yy);
      }
    }
  }
  if (xe == -1) {
    cout << "NO\n";
  } else {
    string way = "";
    for (int x = xe, y = ye; x != xs || y != ys; tie(x, y) = pre[x][y]) {
      way += prec[x][y];
    }
    reverse(way.begin(), way.end());
    cout << "YES\n" << ad[xe][ye] << "\n" << way << "\n";
  }
  return 0;
}
