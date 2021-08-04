#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5, M = 1e6;

struct Line {
  ll a = 0, b = 1e18;
  ll calc(ll x) {
    return a * x + b;
  }
};

int n, s[N], f[N];
vector<Line> ST(4 * M);

void add(int id, int l, int r, Line nw) {
  int m = (l + r) >> 1;
  bool x = nw.calc(l) < ST[id].calc(l);
  bool y = nw.calc(m) < ST[id].calc(m);
  if (y) swap(ST[id], nw);
  if (l == r) return;
  if (x ^ y) {
    add(id << 1, l, m, nw);
  } else {
    add(id << 1 | 1, m + 1, r, nw);
  }
}

ll get(int id, int l, int r, int x) {
  if (l == r) {
    return ST[id].calc(x);
  }
  int m = (l + r) >> 1;
  return min(ST[id].calc(x), x <= m ? get(id << 1, l, m, x) : get(id << 1 | 1, m + 1, r, x));
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> f[0];
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
  }
  ll ans;
  add(1, 1, M, {f[0], 0});
  for (int i = 1; i <= n; ++i) {
    cin >> f[i];
    ans = get(1, 1, M, s[i]);
    add(1, 1, M, {f[i], ans});
  }
  cout << ans;
  return 0;
}
