#include <bits/stdc++.h>
using namespace std;
const int X = 1e6 + 6;

int n, x, c[101], f[X];

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> x;
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
  }
  f[0] = 0;
  for (int i = 1; i <= x; ++i) {
    f[i] = 1e9;
    for (int j = 1; j <= n; ++j) {
      if (i >= c[j]) {
        f[i] = min(f[i], f[i - c[j]] + 1);
      }
    }
  }
  cout << ((f[x] == 1e9) ? -1 : f[x]) << "\n";
  return 0;
}
