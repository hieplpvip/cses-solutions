#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;

int n, room[N];
multimap<int, int> st;
vector<tuple<int, int, int>> A;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 0, l, r; i < n; ++i) {
    cin >> l >> r;
    A.emplace_back(r, l, i);
  }
  sort(A.begin(), A.end());
  for (auto &[r, l, id]: A) {
    auto it = st.lower_bound(l);
    if (it != st.begin()) {
      room[id] = (--it)->second;
      st.erase(it);
    } else {
      room[id] = st.size() + 1;
    }
    st.emplace(r, room[id]);
  }
  cout << st.size() << "\n";
  for (int i = 0; i < n; ++i) {
    cout << room[i] << " \n"[i == n - 1];
  }
  return 0;
}
