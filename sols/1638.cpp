#include <bits/stdc++.h>
using namespace std;

const int N = 1005, MOD = 1e9 + 7;
int n, dp[N][N];

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n;
  dp[0][1] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      char c; cin >> c;
      if (c == '*') {
        dp[i][j] = 0;
      } else {
        dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
      }
    }
  }
  cout << dp[n][n] << "\n";
  return 0;
}
