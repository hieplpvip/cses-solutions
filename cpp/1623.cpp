#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  ll a[n], sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  ll ans = LLONG_MAX;
  for (int mk = 0; mk < (1 << n); ++mk) {
    ll x = 0;
    for (int i = 0; i < n; ++i) {
      if ((mk >> i) & 1) {
        x += a[i];
      }
    }
    ans = min(ans, abs(sum - 2LL * x));
  }
  cout << ans << "\n";
  return 0;
}
