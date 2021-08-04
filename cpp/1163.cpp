#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  set<int> st;
  multiset<int> len;
  int x, n;
  cin >> x >> n;
  st.emplace(0);
  st.emplace(x);
  len.emplace(x);
  for (int i = 0, p; i < n; ++i) {
    cin >> p;
    auto it1 = st.upper_bound(p);
    auto it2 = it1; --it2;
    len.erase(len.find(*it1 - *it2));
    len.emplace(*it1 - p);
    len.emplace(p - *it2);
    st.emplace(p);
    cout << *len.rbegin() << " \n"[i == n - 1];
  }
  return 0;
}
