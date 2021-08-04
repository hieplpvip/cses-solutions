#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  int mx; cin >> mx;
  long long ans = 0;
  for (int i = 2, a; i <= n; ++i) {
    cin >> a;
    if (a < mx) ans += mx - a;
    else mx = a;
  }
  cout << ans << "\n";
  return 0;
}
