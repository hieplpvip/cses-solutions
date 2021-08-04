#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, pw[19], cnt[10], cnt2[10];

bool check(ll x) {
  memset(cnt, 0, sizeof(cnt));
  for (int k = 0; k <= 17; ++k) {
    for (int i = 0; i <= 9; ++i) {
      ll a = (i > 0) ? 0 : 1;
      ll b = x / pw[k + 1];
      while (b * pw[k + 1] + pw[k] * i > x) --b;
      if (a > b) continue;
      cnt[i] += (b - a + 1) * pw[k];
      cnt[i] -= max(0LL, b * pw[k + 1] + pw[k] * (i + 1) - 1 - x);
    }
  }
  for (int i = 0; i <= 9; ++i) {
    if (cnt[i] > n) return false;
  }
  return true;
}

int main() {
  cin >> n;
  pw[0] = 1;
  for (int i = 1; i <= 18; ++i) {
    pw[i] = pw[i - 1] * 10;
  }
  ll lt = 1, rt = 9e17, ans = -1;
  while (lt <= rt) {
    ll mid = (lt + rt) >> 1;
    if (check(mid)) {
      ans = mid;
      lt = mid + 1;
    } else {
      rt = mid - 1;
    }
  }
  cout << ans;
  return 0;
}
