#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n; int k;
  cin >> n >> k;
  ll a[k];
  for (int i = 0; i < k; ++i) {
    cin >> a[i];
  }
  sort(a, a + k);
  k = unique(a, a + k) - a;
  ll ans = 0;
  for (int mk = 1; mk < (1 << k); ++mk) {
    ll lcm = 1;
    for (int i = 0; i < k; ++i) {
      if ((mk >> i) & 1) {
        if ((double)lcm * (double)a[i] > 2e18) {
          lcm = -1;
          break;
        }
        lcm *= a[i];
      }
    }
    if (lcm == -1) continue;
    if (__builtin_popcount(mk) & 1) {
      ans += n / lcm;
    } else {
      ans -= n / lcm;
    }
  }
  cout << ans << "\n";
  return 0;
}
