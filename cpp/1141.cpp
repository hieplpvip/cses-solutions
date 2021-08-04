#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  vector<int> k(n);
  for (int i = 0; i < n; ++i) {
    cin >> k[i];
  }
  int ans = 0;
  set<int> st;
  for (int l = 0, r = 0; l < n; ++l) {
    if (l > 0) {
      st.erase(k[l - 1]);
    }
    while (r < n && !st.count(k[r])) {
      st.emplace(k[r++]);
    }
    ans = max(ans, (int)st.size());
  }
  cout << ans << "\n";
  return 0;
}
