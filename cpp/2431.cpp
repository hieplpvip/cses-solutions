#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int T; cin >> T;
  while (T--) {
    ll k; cin >> k;
    ll pw10 = 1;
    int dig = 1;
    while (true) {
      ll x = 9LL * pw10 * dig;
      if (k > x) k -= x, ++dig, pw10 *= 10;
      else break;
    }
    --k;
    ll x = pw10 + k / dig;
    k %= dig;
    cout << to_string(x)[k] << "\n";
  }
  return 0;
}
