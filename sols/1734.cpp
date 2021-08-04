#include <bits/stdc++.h>
#define L(x) get<0>(x)
#define R(x) get<1>(x)
using namespace std;
using iii = tuple<int, int, int>;
const int N = 2e5 + 5, BLK = 447;

int n, q, x[N], m, cnt[N], ans[N], t;
map<int, int> mp;
iii qq[N];

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
    if (!mp.count(x[i])) {
      mp[x[i]] = ++m;
    }
    x[i] = mp[x[i]];
  }
  for (int i = 1; i <= q; ++i) {
    cin >> L(qq[i]) >> R(qq[i]);
    get<2>(qq[i]) = i;
  }
  sort(qq + 1, qq + 1 + n, [](const iii &a, const iii &b) {
    if (L(a) / BLK != L(b) / BLK) {
      return L(a) < L(b);
    }
    return R(a) < R(b);
  });
  int lastL = 1, lastR = 0;
  for (auto &[L, R, id]: qq) {
    if (lastR < R) {
      for (int i = lastR + 1; i <= R; ++i) {
        if (++cnt[x[i]] == 1) ++t;
      }
    } else {
      for (int i = R + 1; i <= lastR; ++i) {
        if (--cnt[x[i]] == 0) --t;
      }
    }
    if (lastL < L) {
      for (int i = lastL; i < L; ++i) {
        if (--cnt[x[i]] == 0) --t;
      }
    } else {
      for (int i = L; i < lastL; ++i) {
        if (++cnt[x[i]] == 1) ++t;
      }
    }
    lastL = L;
    lastR = R;
    ans[id] = t;
  }
  for (int i = 1; i <= q; ++i) {
    cout << ans[i] << "\n";
  }
  return 0;
}
