#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

struct SegmentTree {
  int val[N << 2], lazy[N << 2];
  void add(int id, int l, int r, int u, int v, int x) {
    if (v < l || r < u) return;
    if (u <= l && r <= v) {
      val[id] += x;
      lazy[id] += x;
      return;
    }
    int mid = (l + r) >> 1;
    if (lazy[id]) {
      val[id << 1] += lazy[id];
      val[id << 1 | 1] += lazy[id];
      lazy[id << 1] += lazy[id];
      lazy[id << 1 | 1] += lazy[id];
      lazy[id] = 0;
    }
    add(id << 1, l, mid, u, v, x);
    add(id << 1 | 1, mid + 1, r, u, v, x);
    val[id] = min(val[id << 1], val[id << 1 | 1]);
  }
};

int n;
SegmentTree st1, st2;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 1, c, s; i <= n; ++i) {
    cin >> c >> s;
    if (s == 1) {
      st1.add(1, 1, n, 1, c, +1);
      st2.add(1, 1, n, 1, c, -1);
    } else {
      st1.add(1, 1, n, 1, c, -1);
      st2.add(1, 1, n, 1, c, +1);
    }
    if (st1.val[1] >= 0) {
      cout << ">\n";
    } else if (st2.val[1] >= 0) {
      cout << "<\n";
    } else {
      cout << "?\n";
    }
  }
  return 0;
}
