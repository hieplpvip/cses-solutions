#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, q, x[N], ST[N << 2];

void build(int id, int l, int r) {
  if (l == r) {
    ST[id] = x[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(id << 1, l, mid);
  build(id << 1 | 1, mid + 1, r);
  ST[id] = min(ST[id << 1], ST[id << 1 | 1]);
}

int get(int id, int l, int r, int u, int v) {
  if (v < l || r < u) return INT_MAX;
  if (u <= l && r <= v) return ST[id];
  int mid = (l + r) >> 1;
  return min(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
}

void update(int id, int l, int r, int u) {
  if (l == r) {
    ST[id] = x[u];
    return;
  }
  int mid = (l + r) >> 1;
  if (u <= mid) update(id << 1, l, mid, u);
  else update(id << 1 | 1, mid + 1, r, u);
  ST[id] = min(ST[id << 1], ST[id << 1 | 1]);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
  }
  build(1, 1, n);
  while (q--) {
    int t, a, b; cin >> t >> a >> b;
    if (t == 1) {
      x[a] = b;
      update(1, 1, n, a);
    } else {
      cout << get(1, 1, n, a, b) << "\n";
    }
  }
  return 0;
}
