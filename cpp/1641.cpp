#include <bits/stdc++.h>
using namespace std;
const int N = 5005;

int n, x, a[N];
map<int, int> mp;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> x;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if (mp.count(x - a[i] - a[j])) {
        cout << mp[x - a[i] - a[j]] << " " << i << " " << j << "\n";
        return 0;
      }
    }
    mp[a[i]] = i;
  }
  cout << "IMPOSSIBLE\n";
  return 0;
}
