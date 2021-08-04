#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7, INV_2 = 500000004;

int main() {
  ll n; cin >> n;
  ll ans = 0;
  ll x = floor(sqrt(n)) + 1;
  for (ll i = 1; i * i <= n; ++i) {
    (ans += (n / i) * i) %= MOD;
    ll y = n / i;
    if (y >= x) {
      (ans += ((((x + y) % MOD) * ((y - x + 1) % MOD)) % MOD) * INV_2) %= MOD;
    }
  }
  cout << ans << "\n";
  return 0;
}
