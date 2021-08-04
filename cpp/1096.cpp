#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

struct Matrix {
  ll a[6][6];
};

Matrix operator*(const Matrix &x, const Matrix &y) {
  Matrix z;
  memset(z.a, 0, sizeof(z.a));
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 6; ++j) {
      for (int k = 0; k < 6; ++k) {
        (z.a[i][j] += x.a[i][k] * y.a[k][j]) %= MOD;
      }
    }
  }
  return z;
}

int main() {
  ll n; cin >> n;
  Matrix x = {1, 2, 4, 8, 16, 32};
  if (n <= 6) {
    cout << x.a[0][n - 1] << "\n";
    return 0;
  }
  n -= 6;
  Matrix y = {};
  for (int i = 0; i < 5; ++i) {
    y.a[i][5] = 1;
    y.a[i + 1][i] = 1;
  }
  y.a[5][5] = 1;
  for (; n; n >>= 1, y = y * y) {
    if (n & 1) {
      x = x * y;
    }
  }
  cout << x.a[0][5] << "\n";
  return 0;
}
