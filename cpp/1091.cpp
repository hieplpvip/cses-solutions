#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n, m; cin >> n >> m;
  multiset<int> st;
  for (int i = 1, p; i <= n; ++i) {
    cin >> p;
    st.emplace(p);
  }
  for (int i = 1, t; i <= m; ++i) {
    cin >> t;
    auto it = st.upper_bound(t);
    if (it != st.begin()) {
      --it;
      cout << *it << "\n";
      st.erase(it);
    } else {
      cout << "-1\n";
    }
  }
  return 0;
}
