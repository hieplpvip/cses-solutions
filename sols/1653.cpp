#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, f[1 << 20];
ll x, w[20], g[1 << 20];

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> x;
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
  }
  f[0] = 1; g[0] = 0;
  for (int mk = 1; mk < (1 << n); ++mk) {
    f[mk] = 1e9;
    for (int i = 0; i < n; ++i) {
      if ((mk >> i) & 1) {
        int newf = f[mk ^ (1 << i)];
        ll newg = g[mk ^ (1 << i)] + w[i];
        if (newg > x) {
          ++newf;
          newg = w[i];
        }
        if (newf < f[mk] || (newf == f[mk] && newg < g[mk])) {
          f[mk] = newf;
          g[mk] = newg;
        }
      }
    }
  }
  cout << f[(1 << n) - 1];
  return 0;
}
