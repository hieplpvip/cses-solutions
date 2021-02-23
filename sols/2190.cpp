#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll = long long;
using pt = pair<ll, ll>;

ll cross(const pt &a, const pt &b, const pt &c) {
  ll t = (a.x - b.x) * (c.y - b.y) - (c.x - b.x) * (a.y - b.y);
  return t >= 0 ? t ? 1 : 0 : -1;
}

bool inter1(ll a, ll b, ll c, ll d) {
  if (a > b) swap(a, b);
  if (c > d) swap(c, d);
  return max(a, c) <= min(b, d);
}

bool inter2(pt p1, pt p2, pt p3, pt p4) {
  if (cross(p1, p2, p3) == 0 && cross(p1, p2, p4) == 0) {
    return inter1(p1.x, p2.x, p3.x, p4.x) && inter1(p1.y, p2.y, p3.y, p4.y);
  }
  return cross(p1, p3, p4) != cross(p2, p3, p4) && cross(p3, p1, p2) != cross(p4, p1, p2);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int T; cin >> T;
  pt p1, p2, p3, p4;
  while (T--) {
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
    cout << (inter2(p1, p2, p3, p4) ? "YES\n" : "NO\n");
  }
  return 0;
}
