#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  int ans = 0;
  unordered_set<int> st;
  for (int k = 30; k >= 0; --k) {
    st.clear();
    st.emplace(0);
    int y = 0;
    bool found = false;
    for (int i = 0; i < n; ++i) {
      y ^= x[i] >> k;
      if (st.count(y ^ ((ans >> k) | 1))) {
        found = true;
        break;
      }
      st.emplace(y);
    }
    if (found) {
      ans |= (1 << k);
    }
  }
  cout << ans;
  return 0;
}
