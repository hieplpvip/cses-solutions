#include <bits/stdc++.h>
using namespace std;
const int N = 505, K = N * N, MOD = 1e9 + 7;

int n, k, f[N][K];

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> k;
  f[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    int x = (i - 1) * (i - 2) / 2;
    int y = i * (i - 1) / 2;
    for (int j = 0; j <= x; ++j) {
      // add f[i - 1][j] to f[i][j -> j + i - 1]
      f[i][j] += f[i - 1][j];
      f[i][j + i] -= f[i - 1][j];
      if (f[i][j] >= MOD) {
        f[i][j] -= MOD;
      }
      if (f[i][j + i] < 0) {
        f[i][j + i] += MOD;
      }
    }
    for (int j = 1; j <= y; ++j) {
      f[i][j] += f[i][j - 1];
      if (f[i][j] >= MOD) {
        f[i][j] -= MOD;
      }
    }
  }
  cout << f[n][k];
  return 0;
}
