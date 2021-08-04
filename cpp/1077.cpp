#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;

int n, k, x[N];
ll sum_min = 0, sum_max = 0;
set<pair<int, int>> st_min, st_max;

void insert(int a, int id) {
  if (!st_min.empty() && a >= st_min.rbegin()->first) {
    sum_max += a;
    st_max.emplace(a, id);
    if (st_max.size() > st_min.size()) {
      a = st_max.begin()->first;
      sum_min += a;
      sum_max -= a;
      st_min.insert(*st_max.begin());
      st_max.erase(st_max.begin());
    }
  } else {
    sum_min += a;
    st_min.emplace(a, id);
    if (st_min.size() > st_max.size() + 1) {
      a = st_min.rbegin()->first;
      sum_max += a;
      sum_min -= a;
      st_max.insert(*st_min.rbegin());
      st_min.erase(--st_min.end());
    }
  }
}

void remove(int a, int id) {
  if (st_min.count({a, id})) {
    sum_min -= a;
    st_min.erase(st_min.find({a, id}));
    if (st_max.size() > st_min.size()) {
      a = st_max.begin()->first;
      sum_min += a;
      sum_max -= a;
      st_min.insert(*st_max.begin());
      st_max.erase(st_max.begin());
    }
  } else {
    sum_max -= a;
    st_max.erase(st_max.find({a, id}));
    if (st_min.size() > st_max.size() + 1) {
      a = st_min.rbegin()->first;
      sum_max += a;
      sum_min -= a;
      st_max.insert(*st_min.rbegin());
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
    insert(x[i], i);
  }
  for (int i = k; i <= n; ++i) {
    if (i > k) {
      remove(x[i - k], i - k);
    }
    insert(x[i], i);
    ll cost = LLONG_MAX;
    if (!st_min.empty()) {
      ll a = st_min.rbegin()->first;
      cost = min(cost, a * (ll)st_min.size() - sum_min + sum_max - a * (ll)st_max.size());
    }
    if (!st_max.empty()) {
      ll a = st_max.begin()->first;
      cost = min(cost, a * (ll)st_min.size() - sum_min + sum_max - a * (ll)st_max.size());
    }
    cout << cost << " \n"[i == n];
  }
  return 0;
}
