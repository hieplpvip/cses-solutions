#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n, x; cin >> n >> x;
  int ans = 0;
  multiset<int> st;
  for (int i = 1, w; i <= n; ++i) {
    cin >> w;
    st.emplace(w);
  }
  while (!st.empty()) {
    ++ans;
    int w = *st.begin();
    st.erase(st.begin());
    auto it = st.upper_bound(x - w);
    if (it != st.begin()) {
      st.erase(--it);
    }
  }
  cout << ans << "\n";
  return 0;
}
