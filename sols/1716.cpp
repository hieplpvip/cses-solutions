#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

ll powmod(ll a, ll b) {
  ll res = 1;
  for (; b; b >>= 1, (a *= a) %= MOD) {
    if (b & 1) {
      (res *= a) %= MOD;
    }
  }
  return res;
}

int main() {
  int n, m; cin >> n >> m;
  m = m + n - 1;
  n = n - 1;
  ll ans = 1;
  for (int i = m; i >= m - n + 1; --i) {
    (ans *= i) %= MOD;
  }
  for (int i = 1; i <= n; ++i) {
    (ans *= powmod(i, MOD - 2)) %= MOD;
  }
  cout << ans << "\n";
  return 0;
}
