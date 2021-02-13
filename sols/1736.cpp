#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;

struct Node {
  ll sum, lazy;
};

int n, q, x[N];
Node ST1[N << 2], ST2[N << 2];

void build1(int id, int l, int r) {
  if (l == r) {
    ST1[id].sum = x[l];
    return;
  }
  int mid = (l + r) >> 1;
  build1(id << 1, l, mid);
  build1(id << 1 | 1, mid + 1, r);
  ST1[id].sum = ST1[id << 1].sum + ST1[id << 1 | 1].sum;
}

void down1(int id, int l, int mid, int r) {
  if (ST1[id].lazy == 0) return;
  ll &k = ST1[id].lazy;
  ST1[id << 1].sum += k * (mid - l + 1);
  ST1[id << 1 | 1].sum += k * (r - mid);
  ST1[id << 1].lazy += k;
  ST1[id << 1 | 1].lazy += k;
  k = 0;
}

void update1(int id, int l, int r, int u, int v, int val) {
  if (v < l || r < u) return;
  if (u <= l && r <= v) {
    ST1[id].sum += 1LL * (r - l + 1) * val;
    ST1[id].lazy += val;
    return;
  }
  int mid = (l + r) >> 1;
  down1(id, l, mid, r);
  update1(id << 1, l, mid, u, v, val);
  update1(id << 1 | 1, mid + 1, r, u, v, val);
  ST1[id].sum = ST1[id << 1].sum + ST1[id << 1 | 1].sum;
}

ll get1(int id, int l, int r, int u, int v) {
  if (v < l || r < u) return 0;
  if (u <= l && r <= v) return ST1[id].sum;
  int mid = (l + r) >> 1;
  down1(id, l, mid, r);
  return get1(id << 1, l, mid, u, v) + get1(id << 1 | 1, mid + 1, r, u, v);
}

void down2(int id, int l, int mid, int r) {
  if (ST2[id].lazy == 0) return;
  ll &k = ST2[id].lazy;
  ST2[id << 1].sum += k * (mid - l + 1) * (l + mid) / 2;
  ST2[id << 1 | 1].sum += k * (r - mid) * (mid + 1 + r) / 2;
  ST2[id << 1].lazy += k;
  ST2[id << 1 | 1].lazy += k;
  k = 0;
}

void update2(int id, int l, int r, int u, int v) {
  if (v < l || r < u) return;
  if (u <= l && r <= v) {
    ST2[id].sum += 1LL * (r - l + 1) * (l + r) / 2;
    ST2[id].lazy += 1;
    return;
  }
  int mid = (l + r) >> 1;
  down2(id, l, mid, r);
  update2(id << 1, l, mid, u, v);
  update2(id << 1 | 1, mid + 1, r, u, v);
  ST2[id].sum = ST2[id << 1].sum + ST2[id << 1 | 1].sum;
}

ll get2(int id, int l, int r, int u, int v) {
  if (v < l || r < u) return 0;
  if (u <= l && r <= v) return ST2[id].sum;
  int mid = (l + r) >> 1;
  down2(id, l, mid, r);
  return get2(id << 1, l, mid, u, v) + get2(id << 1 | 1, mid + 1, r, u, v);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
  }
  build1(1, 1, n);
  for (int i = 1, t, a, b; i <= q; ++i) {
    cin >> t >> a >> b;
    if (t == 1) {
      update1(1, 1, n, a, b, 1 - a);
      update2(1, 1, n, a, b);
    } else {
      cout << get1(1, 1, n, a, b) + get2(1, 1, n, a, b) << "\n";
    }
  }
  return 0;
}
