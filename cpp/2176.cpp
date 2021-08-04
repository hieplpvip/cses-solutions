#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

inline int squares(int i) {
  if (i & 1) {
    return i / 4 * 2 + 1;
  } else {
    return (i - 1) / 4 * 2 + 2;
  }
}

int main() {
  int n, k;
  cin >> n >> k;
  if (k >= 2 * n) {
    cout << 0;
    return 0;
  }
  ll f[2 * n][k + 1] = {};
  f[0][0] = f[1][0] = f[1][1] = 1;
  for (int i = 2; i < 2 * n; ++i) {
    f[i][0] = 1;
    for (int j = 1; j <= k; ++j) {
      f[i][j] = (f[i - 2][j] + f[i - 2][j - 1] * (squares(i) - j + 1)) % MOD;
    }
  }
  ll ans = 0;
  for (int i = 0; i <= k; ++i) {
    (ans += f[2 * n - 1][i] * f[2 * n - 2][k - i]) %= MOD;
  }
  cout << ans;
  return 0;
}
