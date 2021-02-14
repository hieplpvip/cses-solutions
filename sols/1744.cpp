#include <bits/stdc++.h>
using namespace std;

int a, b, f[505][505];

int main() {
  cin >> a >> b;
  for (int i = 1; i <= a; ++i) {
    for (int j = 1; j <= b; ++j) {
      if (i == j) {
        f[i][j] = 0;
        continue;
      }
      f[i][j] = 1e9;
      for (int k = 1; k < i; ++k) {
        f[i][j] = min(f[i][j], f[k][j] + f[i - k][j] + 1);
      }
      for (int k = 1; k < j; ++k) {
        f[i][j] = min(f[i][j], f[i][k] + f[i][j - k] + 1);
      }
    }
  }
  cout << f[a][b] << "\n";
  return 0;
}
