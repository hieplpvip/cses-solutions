#include <bits/stdc++.h>
using namespace std;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n;
double f[101][10][10], g[10][10];

int main() {
  cin >> n;
  for (int i = 1; i <= 8; ++i) {
    for (int j = 1; j <= 8; ++j) {
      g[i][j] = 1;
    }
  }
  for (int i = 1; i <= 8; ++i) {
    for (int j = 1; j <= 8; ++j) {
      memset(f, 0, sizeof(f));
      f[0][i][j] = 1;
      for (int k = 0; k < n; ++k) {
        for (int i1 = 1; i1 <= 8; ++i1) {
          for (int j1 = 1; j1 <= 8; ++j1) {
            int dir = 0;
            for (int h = 0; h < 4; ++h) {
              int i2 = i1 + dx[h];
              int j2 = j1 + dy[h];
              if (1 <= i2 && i2 <= 8 && 1 <= j2 && j2 <= 8) {
                ++dir;
              }
            }
            for (int h = 0; h < 4; ++h) {
              int i2 = i1 + dx[h];
              int j2 = j1 + dy[h];
              f[k + 1][i2][j2] += f[k][i1][j1] / (double)dir;
            }
          }
        }
      }
      for (int ii = 1; ii <= 8; ++ii) {
        for (int jj = 1; jj <= 8; ++jj) {
          g[ii][jj] *= (1 - f[n][ii][jj]);
        }
      }
    }
  }
  double ans = 0;
  for (int i = 1; i <= 8; ++i) {
    for (int j = 1; j <= 8; ++j) {
      ans += g[i][j];
    }
  }
  cout << fixed << setprecision(6) << ans << "\n";
  return 0;
}
