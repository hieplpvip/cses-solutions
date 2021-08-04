#include <bits/stdc++.h>
using namespace std;

// A036685 - OEIS
const set<int> P_pos = {0, 1, 2, 4, 7, 10, 20, 23, 26, 50, 53, 270, 273, 276, 282, 285, 288, 316, 334, 337, 340, 346, 359, 362, 365, 386, 389, 392, 566, 630, 633, 636, 639, 673, 676, 682, 685, 923, 926, 929, 932, 1222};

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int T; cin >> T;
  while (T--) {
    int n; cin >> n;
    cout << (P_pos.count(n) ? "second\n" : "first\n");
  }
  return 0;
}
