#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, n1, n2;
ll x, a[40], ans = 0;
vector<ll> p1, p2;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> x;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  n1 = n / 2;
  n2 = n - n1;
  for (int mk = 0; mk < (1 << n1); ++mk) {
    ll sum = 0;
    for (int i = 0; i < n1; ++i) {
      if ((mk >> i) & 1) {
        sum += a[i];
      }
    }
    p1.emplace_back(sum);
  }
  for (int mk = 0; mk < (1 << n2); ++mk) {
    ll sum = 0;
    for (int i = 0; i < n2; ++i) {
      if ((mk >> i) & 1) {
        sum += a[n1 + i];
      }
    }
    p2.emplace_back(sum);
  }
  sort(p1.begin(), p1.end());
  for (ll &y: p2) {
    ans += upper_bound(p1.begin(), p1.end(), x - y) - lower_bound(p1.begin(), p1.end(), x - y);
  }
  cout << ans << "\n";
  return 0;
}
