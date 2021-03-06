#include <bits/stdc++.h>
using namespace std;

int main() {
  int T, n, x, y;
  cin >> T;
  while (T--) {
    cin >> n;
    y = 0;
    while (n--) {
      cin >> x;
      y ^= x;
    }
    cout << (y ? "first\n" : "second\n");
  }
  return 0;
}
