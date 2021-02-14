#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const int N = 1e6 + 6;

ll f[N][3];

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  f[0][0] = 1;
  for (int i = 1; i < N; ++i) {
    f[i][0] = (2LL * f[i - 1][0] + 3LL * f[i - 1][1] + f[i - 1][2]) % MOD;
    f[i][1] = (f[i - 1][0] + 3LL * f[i - 1][1]) % MOD;
    f[i][2] = (f[i - 1][0] + f[i - 1][2]) % MOD;
  }
  int T; cin >> T;
  while (T--) {
    int n; cin >> n;
    cout << f[n][0] << "\n";
  }
  return 0;
}
