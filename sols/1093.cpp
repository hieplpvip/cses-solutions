#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int n, dp[505][505 * 505];

int main() {
  cin >> n;
  int x = n * (n + 1) / 2;
  if (x & 1) {
    cout << "0\n";
    return 0;
  }
  x /= 2;
  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    dp[i][0] = 1;
    for (int j = 1; j <= x; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (i <= j) {
        (dp[i][j] += dp[i - 1][j - i]) %= MOD;
      }
    }
  }
  cout << ((500000004LL * dp[n][x]) % MOD) << "\n";
  return 0;
}
