#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n; cin >> n;
  ll ans = 0;
  for (int k = 0; (1LL << k) <= n; ++k) {
    ll x = n / (1LL << k);
    ans += (x + 1) / 2 * (1LL << k);
    if (x & 1) {
      ans -= (x + 1) * (1LL << k) - 1 - n;
    }
  }
  cout << ans << "\n";
  return 0;
}
