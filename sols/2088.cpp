#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5005;

int n, h[N][N];
ll x[N], f[N][N];

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
    x[i] += x[i - 1];
    f[i][i] = 0;
    h[i][i] = i;
  }
  for (int d = 1; d < n; ++d) {
    for (int l = 1, r = l + d; r <= n; ++l, ++r) {
      f[l][r] = LLONG_MAX;
      for (int k = h[l][r - 1]; k <= min(h[l + 1][r], r - 1); ++k) {
        if (f[l][r] > f[l][k] + f[k + 1][r]) {
          f[l][r] = f[l][k] + f[k + 1][r];
          h[l][r] = k;
        }
      }
      f[l][r] += x[r] - x[l - 1];
    }
  }
  cout << f[1][n];
  return 0;
}
