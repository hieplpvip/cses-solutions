#include <bits/stdc++.h>
using namespace std;

int main() {
  int T; cin >> T;
  while (T--) {
    int n, y = 0; cin >> n;
    for (int i = 0, x; i < n; ++i) {
      cin >> x;
      if (i & 1) y ^= x;
    }
    cout << (y ? "first\n" : "second\n");
  }
  return 0;
}
