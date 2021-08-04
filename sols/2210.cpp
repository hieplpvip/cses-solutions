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
  ll n; cin >> n; n *= n;
  ll ans = 0;
  (ans += powmod(2, n)) %= MOD;
  (ans += powmod(2, (n + 3) / 4 + 1)) %= MOD;
  (ans += powmod(2, (n + 1) / 2)) %= MOD;
  (ans *= powmod(4, MOD - 2)) %= MOD;
  cout << ans;
  return 0;
}
