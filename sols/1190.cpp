#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

struct Node {
  long long left, right, sum, val;
};

int n, m, x[N];
Node ST[N << 2];

void merge(int id) {
  ST[id].left = max(ST[id << 1].left, ST[id << 1].sum + ST[id << 1 | 1].left);
  ST[id].right = max(ST[id << 1 | 1].right, ST[id << 1 | 1].sum + ST[id << 1].right);
  ST[id].sum = ST[id << 1].sum + ST[id << 1 | 1].sum;
  ST[id].val = max({ST[id << 1].val, ST[id << 1 | 1].val, ST[id << 1].right + ST[id << 1 | 1].left});
}

void build(int id, int l, int r) {
  if (l == r) {
    ST[id].val = ST[id].left = ST[id].right = max(0, x[l]);
    ST[id].sum = x[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(id << 1, l, mid);
  build(id << 1 | 1, mid + 1, r);
  merge(id);
}

void update(int id, int l, int r, int u) {
  if (l == r) {
    ST[id].val = ST[id].left = ST[id].right = max(0, x[l]);
    ST[id].sum = x[l];
    return;
  }
  int mid = (l + r) >> 1;
  if (u <= mid) update(id << 1, l, mid, u);
  else update(id << 1 | 1, mid + 1, r, u);
  merge(id);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
  }
  build(1, 1, n);
  while (m--) {
    int k, a; cin >> k >> a;
    x[k] = a;
    update(1, 1, n, k);
    cout << ST[1].val << "\n";
  }
  return 0;
}
