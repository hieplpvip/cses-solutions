#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 2e5 + 5;
using ll = long long;
using pt = pair<ll, ll>;

int n;
vector<pt> A, hull;

inline ll cross(const pt &a, const pt &b, const pt &c) {
  return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n;
  A.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> A[i].x >> A[i].y;
  }
  sort(A.begin(), A.end());
  for (int i = 0; i < n; ++i) {
    while (hull.size() > 1 && cross(hull[hull.size() - 2], hull.back(), A[i]) < 0) hull.pop_back();
    hull.push_back(A[i]);
  }
  size_t k = hull.size();
  for (int i = n - 2; i >= 0; --i) {
    while (hull.size() > k && cross(hull[hull.size() - 2], hull.back(), A[i]) < 0) hull.pop_back();
    hull.push_back(A[i]);
  }
  hull.pop_back();
  cout << hull.size() << "\n";
  for (auto [x, y]: hull) {
    cout << x << " " << y << "\n";
  }
  return 0;
}
