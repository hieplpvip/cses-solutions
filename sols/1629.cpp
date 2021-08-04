#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  vector<pair<int, int>> movies(n);
  for (int i = 0; i < n; ++i) {
    cin >> movies[i].second >> movies[i].first;
  }
  sort(movies.begin(), movies.end());
  int last = 0, ans = 0;
  for (auto &[r, l]: movies) {
    if (l >= last) {
      ++ans;
      last = r;
    }
  }
  cout << ans << "\n";
  return 0;
}
