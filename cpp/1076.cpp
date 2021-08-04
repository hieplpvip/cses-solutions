#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, k, x[N];
multiset<int> st_min, st_max;

void insert(int a) {
  if (!st_min.empty() && a >= *st_min.rbegin()) {
    st_max.emplace(a);
    if (st_max.size() > st_min.size()) {
      st_min.emplace(*st_max.begin());
      st_max.erase(st_max.begin());
    }
  } else {
    st_min.emplace(a);
    if (st_min.size() > st_max.size() + 1) {
      st_max.emplace(*st_min.rbegin());
      st_min.erase(--st_min.end());
    }
  }
}

void remove(int a) {
  if (st_min.count(a)) {
    st_min.erase(st_min.find(a));
    if (st_max.size() > st_min.size()) {
      st_min.emplace(*st_max.begin());
      st_max.erase(st_max.begin());
    }
  } else {
    st_max.erase(st_max.find(a));
    if (st_min.size() > st_max.size() + 1) {
      st_max.emplace(*st_min.rbegin());
      st_min.erase(--st_min.end());
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
  }
  for (int i = 1; i < k; ++i) {
    insert(x[i]);
  }
  for (int i = k; i <= n; ++i) {
    if (i > k) {
      remove(x[i - k]);
    }
    insert(x[i]);
    cout << *st_min.rbegin() << " \n"[i == n];
  }
  return 0;
}
