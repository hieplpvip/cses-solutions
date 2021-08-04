#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

struct SegmentTree {
  int ST[N << 2];

  void build(int id, int l, int r, int x[]) {
    if (l == r) {
      ST[id] = x[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid, x);
    build(id << 1 | 1, mid + 1, r, x);
    ST[id] = min(ST[id << 1], ST[id << 1 | 1]);
  }

  void update(int id, int l, int r, int u, int val) {
    if (l == r) {
      ST[id] = val;
      return;
    }
    int mid = (l + r) >> 1;
    if (u <= mid) update(id << 1, l, mid, u, val);
    else update(id << 1 | 1, mid + 1, r, u, val);
    ST[id] = min(ST[id << 1], ST[id << 1 | 1]);
  }

  int get(int id, int l, int r, int u, int v) {
    if (v < l || r < u) return INT_MAX;
    if (u <= l && r <= v) return ST[id];
    int mid = (l + r) >> 1;
    return min(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
  }
};

int n, q, p[N], x[N], y[N];
SegmentTree ST1, ST2;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
    x[i] = p[i] - i;
    y[i] = p[i] + i;
  }
  ST1.build(1, 1, n, x);
  ST2.build(1, 1, n, y);
  while (q--) {
    int t, k; cin >> t >> k;
    if (t == 1) {
      cin >> p[k];
      ST1.update(1, 1, n, k, p[k] - k);
      ST2.update(1, 1, n, k, p[k] + k);
    } else {
      cout << min(ST1.get(1, 1, n, 1, k) + k, ST2.get(1, 1, n, k, n) - k) << "\n";
    }
  }
  return 0;
}
