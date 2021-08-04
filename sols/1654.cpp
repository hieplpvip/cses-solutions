#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, K = 20, A = 1 << K;

int n, x[N], f[1 << K], g[1 << K];

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
    ++f[x[i]];
    ++g[x[i]];
  }
  for (int i = 0; i < K; ++i) {
    for (int mk = 0; mk < A; ++mk) {
      if ((mk >> i) & 1) {
        f[mk] += f[mk ^ (1 << i)];
      } else {
        g[mk] += g[mk ^ (1 << i)];
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << f[x[i]] << " " << g[x[i]] << " " << (n - f[x[i] ^ (A - 1)]) << "\n";
  }
  return 0;
}
