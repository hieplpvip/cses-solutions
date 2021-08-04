#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  set<int> st;
  int n; cin >> n;
  while (n--) {
    int x; cin >> x;
    st.emplace(x);
  }
  cout << st.size() << "\n";
  return 0;
}
