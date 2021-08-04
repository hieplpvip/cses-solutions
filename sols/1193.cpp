#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
const int N = 1005;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
const char d[] = {'L', 'R', 'U', 'D'};

int n, m, xstart, ystart, xend, yend, dist[N][N];
char mat[N][N], pred[N][N];
ii pre[N][N];
queue<ii> q;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> mat[i][j];
      if (mat[i][j] == 'A') {
        xstart = i;
        ystart = j;
      } else if (mat[i][j] == 'B') {
        xend = i;
        yend = j;
      }
    }
  }
  memset(dist, -1, sizeof(dist));
  dist[xstart][ystart] = 0;
  q.emplace(xstart, ystart);
  while (!q.empty()) {
    auto [x, y] = q.front(); q.pop();
    for (int k = 0; k < 4; ++k) {
      int xx = x + dx[k];
      int yy = y + dy[k];
      if (xx < 1 || xx > n || yy < 1 || yy > m || mat[xx][yy] == '#' || dist[xx][yy] != -1) continue;
      dist[xx][yy] = dist[x][y] + 1;
      pred[xx][yy] = d[k];
      pre[xx][yy] = {x, y};
      q.emplace(xx, yy);
    }
  }
  if (dist[xend][yend] == -1) {
    cout << "NO\n";
  } else {
    string way = "";
    for (int x = xend, y = yend; x != xstart || y != ystart; tie(x, y) = pre[x][y]) {
      way += pred[x][y];
    }
    reverse(way.begin(), way.end());
    cout << "YES\n" << dist[xend][yend] << "\n" << way << "\n";
  }
  return 0;
}
