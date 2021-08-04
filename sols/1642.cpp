#include <bits/stdc++.h>
using namespace std;
const int N = 1005;

int n, x, a[N];
map<int, pair<int, int>> mp;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> x;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      mp[a[i] + a[j]] = {i, j};
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if (mp[a[i] + a[j]].first == i) {
        mp.erase(a[i] + a[j]);
      }
    }
    for (int j = i - 1; j >= 1; --j) {
      if (mp.count(x - a[i] - a[j])) {
        auto p = mp[x - a[i] - a[j]];
        cout << j << " " << i << " " << p.first << " " << p.second << "\n";
        return 0;
      }
    }
  }
  cout << "IMPOSSIBLE\n";
  return 0;
}
