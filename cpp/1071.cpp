#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int T; cin >> T;
  while (T--) {
    int x, y; cin >> x >> y;
    int layer = max(x, y);
    ll S = 1LL * (layer - 1) * (layer - 1);
    if (layer & 1) {
      if (x == layer) {
        cout << (S + y) << "\n";
      } else {
        cout << (S + layer + layer - x) << "\n";
      }
    } else {
      if (y == layer) {
        cout << (S + x) << "\n";
      } else {
        cout << (S + layer + layer - y) << "\n";
      }
    }
  }
  return 0;
}
