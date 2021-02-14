#pragma GCC target("popcnt")
#include <bits/stdc++.h>
using namespace std;

bitset<100001> f;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  f.set(0);
  for (int i = 1, x; i <= n; ++i) {
    cin >> x;
    f |= f << x;
  }
  int k = 0;
  for (auto i = f._Find_next(0); i < f.size(); i = f._Find_next(i)) {
    ++k;
  }
  cout << k << "\n";
  for (auto i = f._Find_next(0); i < f.size(); i = f._Find_next(i)) {
    cout << i << " ";
  }
  cout << "\n";
  return 0;
}
