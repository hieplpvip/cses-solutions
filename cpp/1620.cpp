#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;

int n;
ll t, k[N];

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> t;
  for (int i = 1; i <= n; ++i) {
    cin >> k[i];
  }
  ll lt = 0, rt = 1e18, ans = -1;
  while (lt <= rt) {
    ll mid = (lt + rt) >> 1;
    ll p = 0;
    for (int i = 1; i <= n; ++i) {
      p += mid / k[i];
      if (p >= t) break;
    }
    if (p >= t) {
      ans = mid;
      rt = mid - 1;
    } else {
      lt = mid + 1;
    }
  }
  cout << ans << "\n";
  return 0;
}
