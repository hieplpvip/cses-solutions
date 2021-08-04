#include <bits/stdc++.h>
using namespace std;

bool mark[1000001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  int ans = 0;
  for (int i = 1, x; i <= n; ++i) {
    cin >> x;
    for (int j = 1; j * j <= x; ++j) {
      if (x % j == 0) {
        if (mark[j]) {
          ans = max(ans, j);
        }
        if (mark[x / j]) {
          ans = max(ans, x / j);
        }
        mark[j] = mark[x / j] = true;
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
