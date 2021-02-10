#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  multiset<int> st;
  int n; cin >> n;
  for (int i = 0, k; i < n; ++i) {
    cin >> k;
    auto it = st.upper_bound(k);
    if (it != st.end()) {
      st.erase(it);
    }
    st.emplace(k);
  }
  cout << st.size() << "\n";
  return 0;
}
