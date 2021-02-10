#pragma GCC target("popcnt")
#include <bits/stdc++.h>
using namespace std;
const int N = 3000;

int n;
bitset<N> r[N];

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      char c; cin >> c;
      if (c == '1') {
        r[i].set(j);
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int x = (r[i] & r[j]).count();
      ans += 1LL * x * (x - 1) / 2;
    }
  }
  cout << ans << "\n";
  return 0;
}
