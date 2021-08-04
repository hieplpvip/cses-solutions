#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const int N = 105, MX = 5000;

int n, x, t[N];
ll f[N][N][2 * MX + 5];

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> x;
  for (int i = 1; i <= n; ++i) {
    cin >> t[i];
  }
  sort(t + 1, t + 1 + n);
  f[0][0][MX] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      for (int k = -MX; k <= MX; ++k) {
        ll c = f[i][j][k + MX];
        // make a team of only person i + 1
        (f[i + 1][j][k + MX] += c) %= MOD;
        // start a new unfinished team with person i + 1
        if (k - t[i + 1] >= -MX) {
          (f[i + 1][j + 1][k - t[i + 1] + MX] += c) %= MOD;
        }
        if (j > 0) {
          // append person i + 1 to an unfinished team
          (f[i + 1][j][k + MX] += j * c) %= MOD;
          // finish an unfinished team with person i + 1
          if (k + t[i + 1] <= MX) {
            (f[i + 1][j - 1][k + t[i + 1] + MX] += j * c) %= MOD;
          }
        }
      }
    }
  }
  ll ans = 0;
  for (int i = 0; i <= x; ++i) {
    (ans += f[n][0][i + MX]) %= MOD;
  }
  cout << ans;
  return 0;
}
