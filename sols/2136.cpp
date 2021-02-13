#pragma GCC target("popcnt")
#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 4;

int n, k;
bitset<30> s[N];

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    char c;
    for (int j = 0; j < k; ++j) {
      cin >> c;
      if (c == '1') {
        s[i].set(j);
      }
    }
  }
  int ans = 999;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      ans = min(ans, (int)(s[i] ^ s[j]).count());
    }
  }
  cout << ans << "\n";
  return 0;
}
