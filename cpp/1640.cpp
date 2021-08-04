#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  map<int, int> mp;
  int n, x; cin >> n >> x;
  for (int i = 1, a; i <= n; ++i) {
    cin >> a;
    if (mp.count(x - a)) {
      cout << mp[x - a] << " " << i << "\n";
      return 0;
    }
    mp[a] = i;
  }
  cout << "IMPOSSIBLE\n";
  return 0;
}
