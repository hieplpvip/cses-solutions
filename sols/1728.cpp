#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  int r[n];
  for (int i = 0; i < n; ++i) {
    cin >> r[i];
  }
  double ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (r[i] <= r[j]) {
        ans += (double)(r[i] - 1) / (double)r[j] / 2.0;
      } else {
        ans += (double)(r[j] - 1) / (double)r[i] / 2.0;
        ans += (double)(r[i] - r[j]) / (double)r[i];
      }
    }
  }
  cout << fixed << setprecision(6) << ans << "\n";
  return 0;
}
