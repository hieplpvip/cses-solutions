#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll = long long;
using ii = pair<int, int>;
const int N = 2e5;

int n;
ii a[N], t[N];
ll mindist = LLONG_MAX;

inline bool cmp_x(const ii &a, const ii &b) {
  return a.x < b.x;
}

inline bool cmp_y(const ii &a, const ii &b) {
  return a.y < b.y;
}

void update(const ii &a, const ii &b) {
  ll dx = a.x - b.x, dy = a.y - b.y;
  mindist = min(mindist, dx * dx + dy * dy);
}

void find(int l, int r) {
  if (r - l <= 1) {
    if (l < r) {
      update(a[l], a[r]);
      if (a[l].y > a[r].y) {
        swap(a[l], a[r]);
      }
    }
    return;
  }
  int m = (l + r) >> 1, mx = a[m].x;
  find(l, m); find(m + 1, r);
  merge(a + l, a + m + 1, a + m + 1, a + r + 1, t, cmp_y);
  copy(t, t + r - l + 1, a + l);
  for (int i = l, ct = 0; i <= r; ++i) {
    if (abs(a[i].x - mx) >= mindist) continue;
    for (int j = ct - 1; j >= 0 && a[i].y - t[j].y < mindist; --j) {
      update(a[i], t[j]);
    }
    t[ct++] = a[i];
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x >> a[i].y;
  }
  sort(a, a + n, cmp_x);
  find(0, n - 1);
  cout << mindist;
  return 0;
}
