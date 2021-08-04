#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7, K = 59049; // 3^10

int n, m, pw3, f[1001][1 << 10], pre[K], nxt[K];
bool good[K];

int main() {
  cin >> n >> m;
  pw3 = pow(3, n);
  for (int mk = 0; mk < pw3; ++mk) {
    vector<int> bit;
    for (int j = 0, tmp = mk; j < n; ++j) {
      bit.emplace_back(tmp % 3);
      tmp /= 3;
    }
    good[mk] = true;
    for (int j = 0; j < n; ++j) {
      if (bit[j] == 0) {
        pre[mk] |= (1 << j);
      } else if (bit[j] == 1) {
        nxt[mk] |= (1 << j);
      } else {
        if (j == n - 1 || bit[j + 1] != 2) {
          good[mk] = false;
          break;
        }
        pre[mk] |= (1 << j) | (1 << (j + 1));
        nxt[mk] |= (1 << j) | (1 << (j + 1));
        ++j;
      }
    }
  }
  f[0][(1 << n) - 1] = 1;
  for (int i = 1; i <= m; ++i) {
    for (int mk = 0; mk < pw3; ++mk) {
      if (good[mk]) {
        f[i][nxt[mk]] += f[i - 1][pre[mk]];
        if (f[i][nxt[mk]] >= MOD) f[i][nxt[mk]] -= MOD;
      }
    }
  }
  cout << f[m][(1 << n) - 1] << "\n";
  return 0;
}
