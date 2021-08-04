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
  int n, m;
  cin >> n >> m;
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    (ans += powmod(m, gcd(i, n))) %= MOD;
  }
  (ans *= powmod(n, MOD - 2)) %= MOD;
  cout << ans;
  return 0;
}
