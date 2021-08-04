#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

struct Matrix {
  ll a, b, c, d;
};

Matrix operator*(const Matrix &x, const Matrix &y) {
  Matrix z;
  z.a = (x.a * y.a + x.b * y.c) % MOD;
  z.b = (x.a * y.b + x.b * y.d) % MOD;
  z.c = (x.c * y.a + x.d * y.c) % MOD;
  z.d = (x.c * y.b + x.d * y.d) % MOD;
  return z;
}

int main() {
  ll n; cin >> n;
  Matrix x = {1, 0, 0, 1};
  Matrix y = {0, 1, 1, 1};
  for (; n; n >>= 1, y = y * y) {
    if (n & 1) {
      x = x * y;
    }
  }
  cout << x.c << "\n";
  return 0;
}
