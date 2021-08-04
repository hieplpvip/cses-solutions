#include <bits/stdc++.h>
using namespace std;
using iii = tuple<int, int, int>;
const int N = 2e5 + 5;

int n, ans1[N], ans2[N];
vector<iii> ranges;
set<int> st;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n;
  ranges.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> get<0>(ranges[i]) >> get<1>(ranges[i]);
    get<2>(ranges[i]) = i;
  }
  sort(ranges.begin(), ranges.end(), [](const iii &a, const iii &b) {
    auto [x1, y1, id1] = a;
    auto [x2, y2, id2] = b;
    if (x1 != x2) return x1 > x2;
    return y1 < y2;
  });
  for (auto &[x, y, id]: ranges) {
    auto it = st.upper_bound(y);
    ans1[id] = (it != st.begin()) ? 1 : 0;
    st.emplace(y);
  }
  sort(ranges.begin(), ranges.end(), [](const iii &a, const iii &b) {
    auto [x1, y1, id1] = a;
    auto [x2, y2, id2] = b;
    if (x1 != x2) return x1 < x2;
    return y1 > y2;
  });
  st.clear();
  for (auto &[x, y, id]: ranges) {
    auto it = st.lower_bound(y);
    ans2[id] = (it != st.end()) ? 1 : 0;
    st.emplace(y);
  }
  for (int i = 0; i < n; ++i) {
    cout << ans1[i] << " \n"[i == n - 1];
  }
  for (int i = 0; i < n; ++i) {
    cout << ans2[i] << " \n"[i == n - 1];
  }
  return 0;
}
