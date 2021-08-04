#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, K = 30;

int n, q, t[N][K];

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> t[i][0];
  }
  for (int k = 1; k < K; ++k) {
    for (int i = 1; i <= n; ++i) {
      t[i][k] = t[t[i][k - 1]][k - 1];
    }
  }
  while (q--) {
    int x, y; cin >> x >> y;
    for (int k = K - 1; k >= 0; --k) {
      if ((1 << k) <= y) {
        x = t[x][k];
        y -= (1 << k);
      }
    }
    cout << x << "\n";
  }
  return 0;
}
