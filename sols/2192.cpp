#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll = long long;
using pt = pair<ll, ll>;

// given 3 colinear points, check if b lies on segment ac
bool on_segment(const pt &a, const pt &b, const pt &c) {
  return min(a.x, c.x) <= b.x && b.x <= max(a.x, c.x) &&
         min(a.y, c.y) <= b.y && b.y <= max(a.y, c.y);
}

inline ll cross(const pt &a, const pt &b, const pt &c) {
  return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pt> A(n), B;
  for (int i = 0; i < n; ++i) {
    cin >> A[i].x >> A[i].y;
  }
  while (m--) {
    pt p; cin >> p.x >> p.y;
    int wn = 0;
    bool b = false;
    for (int i = 0, j = n - 1; i < n; j = i++) {
      ll t = cross(A[j], A[i], p);
      if (t == 0 && on_segment(A[j], p, A[i])) {
        b = true;
        break;
      }
      // winding algorithm
      // we only consider crossing edge with higher y-coordinate strictly larger than p.y
      if (A[j].y <= p.y && p.y < A[i].y) {
        // upward crossing
        if (t > 0) ++wn;
      } else if (A[j].y > p.y && p.y >= A[i].y) {
        // downward crossing
        if (t < 0) --wn;
      }
    }
    cout << (b ? "BOUNDARY\n" : wn ? "INSIDE\n" : "OUTSIDE\n");
  }
  return 0;
}
