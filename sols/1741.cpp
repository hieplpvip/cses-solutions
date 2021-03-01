#include <bits/stdc++.h>
using namespace std;
const int M = 2e6 + 1, Y = 1e6 + 1;

int st1[M << 2], st2[M << 2];
vector<tuple<int, int, int, int>> A;

void update(int id, int l, int r, int u, int v, int t) {
  if (v < l || r < u) return;
  if (u <= l && r <= v) {
    st1[id] += t;
    if (st1[id]) {
      st2[id] = r - l + 1;
    } else if (l < r) {
      st2[id] = st2[id << 1] + st2[id << 1 | 1];
    } else {
      st2[id] = 0;
    }
    return;
  }
  int mid = (l + r) / 2;
  update(id << 1, l, mid, u, v, t);
  update(id << 1 | 1, mid + 1, r, u, v, t);
  if (st1[id]) {
    st2[id] = r - l + 1;
  } else {
    st2[id] = st2[id << 1] + st2[id << 1 | 1];
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  for (int x1, y1, x2, y2; n--;) {
    cin >> x1 >> y1 >> x2 >> y2;
    y1 += Y;
    y2 += Y;
    A.emplace_back(x1, +1, y1, y2);
    A.emplace_back(x2, -1, y1, y2);
  }
  sort(A.begin(), A.end());
  int lastx = 0;
  long long area = 0;
  for (auto [x, t, y1, y2]: A) {
    area += 1LL * (x - lastx) * st2[1];
    update(1, 1, M, y1, y2 - 1, t);
    lastx = x;
  }
  cout << area;
  return 0;
}
