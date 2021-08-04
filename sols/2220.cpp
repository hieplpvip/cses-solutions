#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;

vi to_vi(ll x) {
  vi digs;
  while (x > 0) {
    digs.emplace_back(x % 10);
    x /= 10;
  }
  if (digs.empty()) {
    digs.emplace_back(0);
  }
  return digs;
}

ll f[20][11][2][2];
ll calc(int ind, int pre, int t1, int t2, vi &digs) {
  // t1: are the previous digits the same as digs
  // t2: are the previous digits all zero
  if (ind == -1) return 1;
  if (f[ind][pre][t1][t2] != -1) return f[ind][pre][t1][t2];
  ll res = 0;
  int k = t1 ? digs[ind] : 9;
  for (int i = 0; i <= k; ++i) {
    if (i != pre || (t2 && (i == 0))) {
      res += calc(ind - 1, i, t1 & (i == k), t2 & (i == 0), digs);
    }
  }
  return (f[ind][pre][t1][t2] = res);
}

int main() {
  ll a, b; cin >> a >> b;
  vi B = to_vi(b);
  memset(f, -1, sizeof(f));
  ll ans = calc((int)B.size() - 1, 10, 1, 1, B);
  if (a > 0) {
    vi A = to_vi(a - 1);
    memset(f, -1, sizeof(f));
    ans -= calc((int)A.size() - 1, 10, 1, 1, A);
  }
  cout << ans << "\n";
  return 0;
}
