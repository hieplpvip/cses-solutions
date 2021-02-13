#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, x[N], y[N], f[N], fen[N], ans;

void update(int p, int v) {
  for (; p <= n; p += p & -p) {
    fen[p] = max(fen[p], v);
  }
}

int get(int p) {
  int v = 0;
  for (; p >= 1; p -= p & -p) {
    v = max(v, fen[p]);
  }
  return v;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
    y[i] = x[i];
  }
  sort(y + 1, y + 1 + n);
  for (int i = 1; i <= n; ++i) {
    int p = lower_bound(y + 1, y + 1 + n, x[i]) - y;
    f[i] = get(p - 1) + 1;
    ans = max(ans, f[i]);
    update(p, f[i]);
  }
  cout << ans << "\n";
  return 0;
}
