#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  while (n--) {
    int x; cin >> x;
    int ans = 0;
    for (int i = 1; i * i <= x; ++i) {
      if (x % i == 0) {
        ++ans;
        if (i * i != x) ++ans;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
