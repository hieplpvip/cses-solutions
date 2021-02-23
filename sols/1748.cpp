#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, MOD = 1e9 + 7;

int n, x[N], y[N], f[N], fen[N], ans;

void add(int p, int v) {
  for (; p <= n; p += p & -p) {
    fen[p] += v;
    if (fen[p] >= MOD) fen[p] -= MOD;
  }
}

int get(int p) {
  int v = 0;
  for (; p >= 1; p -= p & -p) {
    v += fen[p];
    if (v >= MOD) v -= MOD;
  }
  return v;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
    y[i] = i;
  }
  sort(y + 1, y + 1 + n, [&](const int &a, const int &b) {
    return x[a] < x[b];
  });
  for (int i = 1, last = -1, m = 0; i <= n; ++i) {
    if (x[y[i]] != last) ++m;
    last = x[y[i]];
    x[y[i]] = m;
  }
  for (int i = 1; i <= n; ++i) {
    f[i] = 1 + get(x[i] - 1);
    if (f[i] >= MOD) f[i] -= MOD;
    ans += f[i];
    if (ans >= MOD) ans -= MOD;
    add(x[i], f[i]);
  }
  cout << ans;
  return 0;
}
