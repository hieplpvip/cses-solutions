#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;

int n, q, x[N];
ll sum[N], ST[N << 2], lazy[N << 2];

void build(int id, int l, int r) {
  if (l == r) {
    ST[id] = sum[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(id << 1, l, mid);
  build(id << 1 | 1, mid + 1, r);
  ST[id] = max(ST[id << 1], ST[id << 1 | 1]);
}

void down(int id) {
  if (lazy[id] == 0) return;
  ST[id << 1] += lazy[id];
  ST[id << 1 | 1] += lazy[id];
  lazy[id << 1] += lazy[id];
  lazy[id << 1 | 1] += lazy[id];
  lazy[id] = 0;
}

void update(int id, int l, int r, int u, int v, ll val) {
  if (v < l || r < u) return;
  if (u <= l && r <= v) {
    ST[id] += val;
    lazy[id] += val;
    return;
  }
  down(id);
  int mid = (l + r) >> 1;
  update(id << 1, l, mid, u, v, val);
  update(id << 1 | 1, mid + 1, r, u, v, val);
  ST[id] = max(ST[id << 1], ST[id << 1 | 1]);
}

ll get(int id, int l, int r, int u, int v) {
  if (v < l || r < u) return LLONG_MIN;
  if (u <= l && r <= v) return ST[id];
  down(id);
  int mid = (l + r) >> 1;
  return max(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
  }
  for (int i = 1; i <= n; ++i) {
    sum[i] = sum[i - 1] + x[i];
  }
  build(1, 1, n);
  while (q--) {
    int t, a, b; cin >> t >> a >> b;
    if (t == 1) {
      update(1, 1, n, a, n, b - x[a]);
      x[a] = b;
    } else {
      ll pre = (a == 1) ? 0 : get(1, 1, n, a - 1, a - 1);
      ll mx = max(get(1, 1, n, a, b), pre) - pre;
      cout << mx << "\n";
    }
  }
  return 0;
}
