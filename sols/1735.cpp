#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;

struct Node {
  ll sum, lazy1, lazy2;
};

int n, q, t[N];
Node ST[N << 2];

void build(int id, int l, int r) {
  if (l == r) {
    ST[id].sum = t[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(id << 1, l, mid);
  build(id << 1 | 1, mid + 1, r);
  ST[id].sum = ST[id << 1].sum + ST[id << 1 | 1].sum;
}

void down(int id, int l, int mid, int r) {
  if (ST[id].lazy2 != 0) {
    ll x = ST[id].lazy2;
    ST[id << 1].sum = 1LL * (mid - l + 1) * x;
    ST[id << 1 | 1].sum = 1LL * (r - mid) * x;
    ST[id << 1].lazy1 = ST[id << 1 | 1].lazy1 = 0;
    ST[id << 1].lazy2 = ST[id << 1 | 1].lazy2 = x;
    ST[id].lazy2 = 0;
  }
  if (ST[id].lazy1 != 0) {
    ll x = ST[id].lazy1;
    ST[id << 1].sum += 1LL * (mid - l + 1) * x;
    ST[id << 1 | 1].sum += 1LL * (r - mid) * x;
    ST[id << 1].lazy1 += x;
    ST[id << 1 | 1].lazy1 += x;
    ST[id].lazy1 = 0;
  }
}

void update1(int id, int l, int r, int u, int v, int x) {
  if (v < l || r < u) return;
  if (u <= l && r <= v) {
    ST[id].sum += 1LL * (r - l + 1) * x;
    ST[id].lazy1 += x;
    return;
  }
  int mid = (l + r) >> 1;
  down(id, l, mid, r);
  update1(id << 1, l, mid, u, v, x);
  update1(id << 1 | 1, mid + 1, r, u, v, x);
  ST[id].sum = ST[id << 1].sum + ST[id << 1 | 1].sum;
}

void update2(int id, int l, int r, int u, int v, int x) {
  if (v < l || r < u) return;
  if (u <= l && r <= v) {
    ST[id].sum = 1LL * (r - l + 1) * x;
    ST[id].lazy1 = 0;
    ST[id].lazy2 = x;
    return;
  }
  int mid = (l + r) >> 1;
  down(id, l, mid, r);
  update2(id << 1, l, mid, u, v, x);
  update2(id << 1 | 1, mid + 1, r, u, v, x);
  ST[id].sum = ST[id << 1].sum + ST[id << 1 | 1].sum;
}

ll get(int id, int l, int r, int u, int v) {
  if (v < l || r < u) return 0;
  if (u <= l && r <= v) return ST[id].sum;
  int mid = (l + r) >> 1;
  down(id, l, mid, r);
  return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> t[i];
  }
  build(1, 1, n);
  for (int i = 1, t, a, b, x; i <= q; ++i) {
    cin >> t >> a >> b;
    if (t == 1) {
      cin >> x;
      update1(1, 1, n, a, b, x);
    } else if (t == 2) {
      cin >> x;
      update2(1, 1, n, a, b, x);
    } else {
      cout << get(1, 1, n, a, b) << "\n";
    }
  }
  return 0;
}
