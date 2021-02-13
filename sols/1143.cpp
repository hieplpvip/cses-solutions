#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, m, h[N], ST[N << 2];

void build(int id, int l, int r) {
  if (l == r) {
    ST[id] = h[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(id << 1, l, mid);
  build(id << 1 | 1, mid + 1, r);
  ST[id] = max(ST[id << 1], ST[id << 1 | 1]);
}

void update(int id, int l, int r, int u) {
  if (l == r) {
    ST[id] = h[u];
    return;
  }
  int mid = (l + r) >> 1;
  if (u <= mid) update(id << 1, l, mid, u);
  else update(id << 1 | 1, mid + 1, r, u);
  ST[id] = max(ST[id << 1], ST[id << 1 | 1]);
}

int get(int id, int l, int r, int x) {
  if (ST[id] < x) return 0;
  if (l == r) return l;
  int mid = (l + r) >> 1;
  if (ST[id << 1] >= x) return get(id << 1, l, mid, x);
  else return get(id << 1 | 1, mid + 1, r, x);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> h[i];
  }
  build(1, 1, n);
  for (int i = 1, r; i <= m; ++i) {
    cin >> r;
    int p = get(1, 1, n, r);
    cout << p << " \n"[i == m];
    if (p) {
      h[p] -= r;
      update(1, 1, n, p);
    }
  }
  return 0;
}
