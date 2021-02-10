#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n, k; cin >> n >> k;
  vector<pair<int, int>> movies(n);
  for (int i = 0; i < n; ++i) {
    cin >> movies[i].second >> movies[i].first;
  }
  sort(movies.begin(), movies.end());
  int ans = 0;
  multiset<int> last;
  for (auto &[r, l]: movies) {
    auto it = last.upper_bound(l);
    if (it != last.begin()) {
      ++ans;
      last.erase(--it);
      last.emplace(r);
    } else if ((int)last.size() < k) {
      ++ans;
      last.emplace(r);
    }
  }
  cout << ans << "\n";
  return 0;
}
