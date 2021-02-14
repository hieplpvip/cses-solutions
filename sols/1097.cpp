#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5005;

int n;
ll x[N], sum[N], f[N][N];

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
    sum[i] = sum[i - 1] + x[i];
    f[i][i] = x[i];
  }
  for (int d = 2; d <= n; ++d) {
    for (int l = 1, r = d; r <= n; ++l, ++r) {
      f[l][r] = max(x[l] + sum[r] - sum[l] - f[l + 1][r], x[r] + sum[r - 1] - sum[l - 1] - f[l][r - 1]);
    }
  }
  cout << f[1][n] << "\n";
  return 0;
}
