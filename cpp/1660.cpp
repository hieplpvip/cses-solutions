#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  map<ll, ll> mp;
  int n; cin >> n;
  ll x; cin >> x;
  ll sum = 0, ans = 0;
  mp[0] = 1;
  for (int i = 1, a; i <= n; ++i) {
    cin >> a;
    sum += a;
    if (mp.count(sum - x)) {
      ans += mp[sum - x];
    }
    ++mp[sum];
  }
  cout << ans << "\n";
  return 0;
}
