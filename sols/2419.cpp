#include <bits/stdc++.h>
using namespace std;

int fact(int x) {
  int res = 0;
  for (; x; x >>= 1) {
    res += (x >> 1);
  }
  return res;
}

int C(int n, int k) {
  return fact(n) - fact(k) - fact(n - k);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n, ans = 0;
  cin >> n;
  for (int i = 1, x; i <= n; ++i) {
    cin >> x;
    if (C(n - 1, i - 1) == 0) {
      ans ^= x;
    }
  }
  cout << ans;
  return 0;
}
