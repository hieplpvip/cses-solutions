#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k; cin >> n >> k;
  double ans = k;
  for (int i = 1; i < k; ++i) {
    ans -= pow((double)i / (double)k, n);
  }
  cout << fixed << setprecision(6) << ans << "\n";
  return 0;
}
