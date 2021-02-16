#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, K = 20;

int n, q, p[N][K];

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> q;
  memset(p, -1, sizeof(p));
  for (int i = 2; i <= n; ++i) {
    cin >> p[i][0];
  }
  for (int k = 1; (1 << k) <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      if (p[i][k - 1] != -1) {
        p[i][k] = p[p[i][k - 1]][k - 1];
      }
    }
  }
  while (q--) {
    int x, y; cin >> x >> y;
    for (int k = K - 1; k >= 0 && x != -1; --k) {
      if (y >= (1 << k)) {
        x = p[x][k];
        y -= (1 << k);
      }
    }
    cout << x << "\n";
  }
  return 0;
}
