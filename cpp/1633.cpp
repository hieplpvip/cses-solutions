#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6, MOD = 1e9 + 7;

int n, f[N];

int main() {
  cin >> n;
  f[0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= 6; ++j) {
      if (i >= j) {
        (f[i] += f[i - j]) %= MOD;
      }
    }
  }
  cout << f[n] << "\n";
  return 0;
}
