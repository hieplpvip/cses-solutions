#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using iii = tuple<int, int, int>;
const int N = 2e5 + 5;

int n, ans1[N], ans2[N];
vector<iii> ranges;
tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> st;

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
    ans1[id] = st.order_of_key(y + 1);
    st.insert(y);
  }
  sort(ranges.begin(), ranges.end(), [](const iii &a, const iii &b) {
    auto [x1, y1, id1] = a;
    auto [x2, y2, id2] = b;
    if (x1 != x2) return x1 < x2;
    return y1 > y2;
  });
  st.clear();
  for (auto &[x, y, id]: ranges) {
    ans2[id] = (int)st.size() - st.order_of_key(y);
    st.insert(y);
  }
  for (int i = 0; i < n; ++i) {
    cout << ans1[i] << " \n"[i == n - 1];
  }
  for (int i = 0; i < n; ++i) {
    cout << ans2[i] << " \n"[i == n - 1];
  }
  return 0;
}
