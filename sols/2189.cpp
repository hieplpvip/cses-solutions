#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int T; cin >> T;
  while (T--) {
    ll x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    ll cross = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
    if (cross > 0) {
      cout << "LEFT\n";
    } else if (cross < 0) {
      cout << "RIGHT\n";
    } else {
      cout << "TOUCH\n";
    }
  }
  return 0;
}
