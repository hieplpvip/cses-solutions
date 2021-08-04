#include <bits/stdc++.h>
using namespace std;
const int N = 1005, X = 1e5 + 5;

int n, x, h[N], s[N], f[2][X];

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> x;
  for (int i = 1; i <= n; ++i) {
    cin >> h[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= x; ++j) {
      f[i & 1][j] = f[(i - 1) & 1][j];
      if (j >= h[i]) {
        f[i & 1][j] = max(f[i & 1][j], f[(i - 1) & 1][j - h[i]] + s[i]);
      }
    }
  }
  int ans = 0;
  for (int j = 1; j <= x; ++j) {
    ans = max(ans, f[n & 1][j]);
  }
  cout << ans << "\n";
  return 0;
}
