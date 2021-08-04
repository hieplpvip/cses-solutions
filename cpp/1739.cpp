#include <bits/stdc++.h>
using namespace std;
const int N = 1005;

int n, q, fen[N][N];
char mat[N][N];

void add(int x, int y, int v) {
  for (; x < N; x += x & -x) {
    for (int ty = y; ty < N; ty += ty & -ty) {
      fen[x][ty] += v;
    }
  }
}

int get(int x, int y) {
  int v = 0;
  for (; x > 0; x -= x & -x) {
    for (int ty = y; ty > 0; ty -= ty & -ty) {
      v += fen[x][ty];
    }
  }
  return v;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> mat[i][j];
      if (mat[i][j] == '*') {
        add(i, j, 1);
      }
    }
  }
  while (q--) {
    int t; cin >> t;
    if (t == 1) {
      int x, y; cin >> x >> y;
      if (mat[x][y] == '.') {
        add(x, y, 1);
        mat[x][y] = '*';
      } else {
        add(x, y, -1);
        mat[x][y] = '.';
      }
    } else {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      cout << get(x2, y2) - get(x2, y1 - 1) - get(x1 - 1, y2) + get(x1 - 1, y1 - 1) << "\n";
    }
  }
  return 0;
}
