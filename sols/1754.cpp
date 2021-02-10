#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int T; cin >> T;
  while (T--) {
    int a, b; cin >> a >> b;
    // a = x + 2y
    // b = 2x + y
    if ((a + b) % 3 != 0) {
      cout << "NO\n";
      continue;
    }
    int sum = (a + b) / 3; // x + y
    int diff = b - a;      // x - y
    if ((sum + diff) % 2 != 0) {
      cout << "NO\n";
      continue;
    }
    int x = (sum + diff) / 2;
    int y = sum - x;
    if (x >= 0 && y >= 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
