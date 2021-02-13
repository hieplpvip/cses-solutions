#include <bits/stdc++.h>
using namespace std;
const int X = 1e6 + 6, MOD = 1e9 + 7;

int n, x, c[105], f[X];

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> x;
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
  }
  f[0] = 1;
  for (int j = 1; j <= x; ++j) {
    for (int i = 1; i <= n; ++i) {
      if (j >= c[i]) {
        (f[j] += f[j - c[i]]) %= MOD;
      }
    }
  }
  cout << f[x] << "\n";
  return 0;
}
