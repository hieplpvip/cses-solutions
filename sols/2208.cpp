#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int T; cin >> T;
  while (T--) {
    int n, x;
    bool first = false;
    cin >> n;
    while (n--) {
      cin >> x;
      if (x & 1) first = true;
    }
    cout << (first ? "first\n" : "second\n");
  }
  return 0;
}
