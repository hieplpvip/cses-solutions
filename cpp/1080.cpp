#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const int N = 505;

int n;
string s;
ll C[N][N], f[N][N];

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  C[0][0] = 1;
  for (int i = 1; i < N; ++i) {
    C[i][0] = 1;
    for (int j = 1; j < N; ++j) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }
  }

  cin >> s;
  n = s.length();
  s = "#" + s;
  for (int i = 0; i <= n; ++i) {
    f[i + 1][i] = 1;
  }
  for (int d = 2; d <= n; d += 2) {
    for (int l = 1, r = d; r <= n; ++l, ++r) {
      for (int k = l + 1; k <= r; k += 2) {
        if (s[l] == s[k]) {
          (f[l][r] += f[l + 1][k - 1] * f[k + 1][r] % MOD * C[(r - l + 1) / 2][(r - k) / 2] % MOD) %= MOD;
        }
      }
    }
  }
  cout << f[1][n] << "\n";
  return 0;
}
