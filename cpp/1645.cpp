#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, x[N], ans[N];
vector<int> delay;
vector<pair<int, int>> A;
set<int> st;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
    A.emplace_back(x[i], i);
  }
  sort(A.begin(), A.end());
  for (auto &[v, p]: A) {
    if (!delay.empty() && v != x[delay.back()]) {
      for (int &k: delay) {
        st.emplace(k);
      }
      delay.clear();
    }
    auto it = st.lower_bound(p);
    ans[p] = it == st.begin() ? 0 : *(--it);
    delay.emplace_back(p);
  }
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " \n"[i == n];
  }
  return 0;
}
