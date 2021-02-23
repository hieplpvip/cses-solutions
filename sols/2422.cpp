#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n; cin >> n;
  ll lt = 1, rt = 1LL * n * n, ans = -1, med = (rt + 1) / 2;
  while (lt <= rt) {
    ll md = (lt + rt) >> 1;
    ll cnt = 0;
    for (int i = 1; i <= n; ++i) {
      cnt += min(md / i, (ll)n);
    }
    if (cnt >= med) {
      ans = md;
      rt = md - 1;
    } else {
      lt = md + 1;
    }
  }
  cout << ans;
  return 0;
}
