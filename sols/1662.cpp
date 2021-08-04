#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  long long ans = 0;
  map<int, int> mp;
  mp[0] = 1;
  for (int i = 1, sum = 0, a; i <= n; ++i) {
    cin >> a;
    (((sum += a) %= n) += n) %= n;
    ans += mp[sum];
    ++mp[sum];
  }
  cout << ans << "\n";
  return 0;
}
