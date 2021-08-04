#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const int N = 100;

struct Matrix {
  ll x[N][N];
};

Matrix operator*(const Matrix &a, const Matrix &b) {
  Matrix c;
  memset(c.x, 0, sizeof(c.x));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < N; ++k) {
        (c.x[i][j] += a.x[i][k] * b.x[k][j]) %= MOD;
      }
    }
  }
  return c;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  Matrix x;
  memset(x.x, 0, sizeof(x.x));
  while (m--) {
    int u, v;
    cin >> u >> v;
    ++x.x[--u][--v];
  }
  Matrix y = x;
  for (--k; k; k >>= 1, y = y * y) {
    if (k & 1) {
      x = x * y;
    }
  }
  cout << x.x[0][n - 1] << "\n";
  return 0;
}
