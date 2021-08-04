#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;
const ll MOD = 1e9 + 2277, BASE = 31;

ll pw[N];

struct SegmentTree {
  ll ST[N << 2];

  void build(int id, int l, int r, const string &s) {
    if (l == r) {
      ST[id] = s[l - 1] - 'a';
      return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid, s);
    build(id << 1 | 1, mid + 1, r, s);
    ST[id] = (ST[id << 1] * pw[r - mid] + ST[id << 1 | 1]) % MOD;
  }

  void update(int id, int l, int r, int u, int v) {
    if (l == r) {
      ST[id] = v;
      return;
    }
    int mid = (l + r) >> 1;
    if (u <= mid) {
      update(id << 1, l, mid, u, v);
    } else {
      update(id << 1 | 1, mid + 1, r, u, v);
    }
    ST[id] = (ST[id << 1] * pw[r - mid] + ST[id << 1 | 1]) % MOD;
  }

  pair<ll, int> get(int id, int l, int r, int u, int v) {
    if (v < l || r < u) return {0, 0};
    if (u <= l && r <= v) return {ST[id], r - l + 1};
    int mid = (l + r) >> 1;
    auto left = get(id << 1, l, mid, u, v);
    auto right = get(id << 1 | 1, mid + 1, r, u, v);
    return {(left.first * pw[right.second] + right.first) % MOD, left.second + right.second};
  }
};

int n, m;
string s, t;
SegmentTree st1, st2;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  pw[0] = 1;
  for (int i = 1; i < N; ++i) {
    pw[i] = (pw[i - 1] * BASE) % MOD;
  }
  cin >> n >> m >> s;
  t = string(s.rbegin(), s.rend());
  st1.build(1, 1, n, s);
  st2.build(1, 1, n, t);
  while (m--) {
    int t; cin >> t;
    if (t == 1) {
      int k; char x;
      cin >> k >> x;
      st1.update(1, 1, n, k, x - 'a');
      st2.update(1, 1, n, n - k + 1, x - 'a');
    } else {
      int a, b;
      cin >> a >> b;
      if (st1.get(1, 1, n, a, b) == st2.get(1, 1, n, n - b + 1, n - a + 1)) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
  return 0;
}
