#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  double f[b + 1] = {};
  f[0] = 1;
  for (int k = 1; k <= n; ++k) {
    for (int i = b; i >= 1; --i) {
      f[i] = 0;
      for (int j = max(0, i - 6); j < i; ++j) {
        f[i] += f[j];
      }
      f[i] /= 6.0;
    }
    f[0] = 0;
  }
  double ans = 0;
  for (int i = a; i <= b; ++i) {
    ans += f[i];
  }
  cout << fixed << setprecision(6) << ans << "\n";
  return 0;
}
