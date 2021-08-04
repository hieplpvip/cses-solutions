#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  vector<pair<int, int>> guest(n);
  for (int i = 0; i < n; ++i) {
    cin >> guest[i].first >> guest[i].second;
  }
  sort(guest.begin(), guest.end());
  priority_queue<int> pq;
  int ans = 0;
  for (auto &[l, r]: guest) {
    pq.emplace(-r);
    while (!pq.empty() && -pq.top() < l) pq.pop();
    ans = max(ans, (int)pq.size());
  }
  cout << ans << "\n";
  return 0;
}
