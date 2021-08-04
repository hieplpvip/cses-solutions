#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-2, -2, -1, -1, +1, +1, +2, +2};
const int dy[] = {-1, +1, -2, +2, -2, +2, -1, +1};

int ord[8][8];

int deg(int x, int y) {
  int res = 0;
  for (int k = 0; k < 8; ++k) {
    int xx = x + dx[k];
    int yy = y + dy[k];
    if (0 <= xx && xx < 8 && 0 <= yy && yy < 8 && !ord[xx][yy]) {
      ++res;
    }
  }
  return res;
}

bool find(int x, int y, int t) {
  ord[x][y] = t;
  if (t == 64) return true;
  vector<tuple<int, int, int>> A;
  for (int k = 0; k < 8; ++k) {
    int xx = x + dx[k];
    int yy = y + dy[k];
    if (0 <= xx && xx < 8 && 0 <= yy && yy < 8 && !ord[xx][yy]) {
      A.emplace_back(deg(xx, yy), xx, yy);
    }
  }
  sort(A.begin(), A.end()); // Warnsdorff's rule
  for (auto [d, xx, yy]: A) {
    if (find(xx, yy, t + 1)) return true;
  }
  ord[x][y] = 0;
  return false;
}

int main() {
  int x, y;
  cin >> x >> y;
  find(y - 1, x - 1, 1);
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      cout << ord[i][j] << " \n"[j == 7];
    }
  }
  return 0;
}
