#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 5;
int n, k, a[N];

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  ll lt = *max_element(a + 1, a + 1 + n), rt = 2e14, ans = -1;
  while (lt <= rt) {
    ll mid = (lt + rt) >> 1;
    ll sum = 0;
    int c = 1;
    for (int i = 1; i <= n; ++i) {
      if (sum + a[i] > mid) {
        sum = 0;
        ++c;
      }
      sum += a[i];
    }
    if (c <= k) {
      ans = mid;
      rt = mid - 1;
    } else {
      lt = mid + 1;
    }
  }
  cout << ans << "\n";
  return 0;
}
