#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 4e5 + 5, H = 20;

int n, m, x[N], nxt[N][H];
ll k, sum[N];

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> k;
  m = 2 * n;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
    x[i + n] = x[i];
  }
  for (int i = 1; i <= m; ++i) {
    sum[i] = sum[i - 1] + x[i];
  }
  memset(nxt, -1, sizeof(nxt));
  for (int i = m; i >= 1; --i) {
    nxt[i][0] = upper_bound(sum + 1, sum + 1 + m, sum[i - 1] + k) - sum;
  }
  for (int h = 1; (1 << h) <= m; ++h) {
    for (int i = 1; i <= m; ++i) {
      if (nxt[i][h - 1] != -1) {
        nxt[i][h] = nxt[nxt[i][h - 1]][h - 1];
      }
    }
  }
  int ans = INT_MAX;
  for (int i = 1; i <= n; ++i) {
    int tans = 1, j = i;
    for (int h = H - 1; h >= 0; --h) {
      if (nxt[j][h] != -1 && nxt[j][h] < i + n) {
        tans += (1 << h);
        j = nxt[j][h];
      }
    }
    ans = min(ans, tans);
  }
  cout << ans;
  return 0;
}
