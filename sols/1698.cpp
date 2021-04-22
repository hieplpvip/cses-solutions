#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, k, a[N];
bool mark[N];
vector<pair<int, int>> rounds[2];

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    if (mark[i]) continue;
    vector<int> cycle;
    for (int j = i; !mark[j]; j = a[j]) {
      cycle.emplace_back(j);
      mark[j] = true;
    }
    for (int l = 1, r = (int)cycle.size() - 1; l < r; ++l, --r) {
      rounds[k].emplace_back(cycle[l], cycle[r]);
      swap(a[cycle[l]], a[cycle[r]]);
    }
  }
  if (!rounds[k].empty()) {
    ++k;
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i] != i && a[i] < i) {
      assert(a[a[i]] == i);
      rounds[k].emplace_back(i, a[i]);
    }
  }
  if (!rounds[k].empty()) {
    ++k;
  }
  cout << k << "\n";
  for (int i = 0; i < k; ++i) {
    cout << rounds[i].size() << "\n";
    for (auto [x, y]: rounds[i]) {
      cout << x << " " << y << "\n";
    }
  }
  return 0;
}
