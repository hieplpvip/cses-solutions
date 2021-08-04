#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n; cin >> n;
  ll cnt2 = 0, cnt5 = 0;
  for (ll i = 2; i <= n; i *= 2) cnt2 += n / i;
  for (ll i = 5; i <= n; i *= 5) cnt5 += n / i;
  cout << min(cnt2, cnt5) << "\n";
  return 0;
}
