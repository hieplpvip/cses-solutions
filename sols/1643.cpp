#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  ll sum = 0, minsum = 0, ans = LLONG_MIN;
  for (int i = 1, a; i <= n; ++i) {
    cin >> a;
    sum += a;
    ans = max(ans, sum - minsum);
    minsum = min(minsum, sum);
  }
  cout << ans << "\n";
  return 0;
}
