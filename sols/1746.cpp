#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7, N = 1e5 + 5, M = 105;

int n, m, x[N], f[N][M];

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
  }
  if (x[1]) {
    f[1][x[1]] = 1;
  } else {
    fill(f[1] + 1, f[1] + 1 + m, 1);
  }
  for (int i = 2; i <= n; ++i) {
    if (x[i]) {
      f[i][x[i]] = f[i - 1][x[i]];
      if (x[i] > 1) {
        (f[i][x[i]] += f[i - 1][x[i] - 1]) %= MOD;
      }
      if (x[i] < m) {
        (f[i][x[i]] += f[i - 1][x[i] + 1]) %= MOD;
      }
    } else {
      for (int j = 1; j <= m; ++j) {
        f[i][j] = f[i - 1][j];
        if (j > 1) {
          (f[i][j] += f[i - 1][j - 1]) %= MOD;
        }
        if (j < m) {
          (f[i][j] += f[i - 1][j + 1]) %= MOD;
        }
      }
    }
  }
  int ans = 0;
  for (int j = 1; j <= m; ++j) {
    (ans += f[n][j]) %= MOD;
  }
  cout << ans << "\n";
  return 0;
}
