#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

int main() {
  string s; cin >> s;
  map<vi, int> mp;
  vi cnt(26, 0), a;
  for (char c: s) {
    ++cnt[c - 'a'];
  }
  for (int i = 0; i < 26; ++i) {
    if (cnt[i]) {
      a.emplace_back(i);
      cnt[i] = 0;
    }
  }
  int n = a.size();
  vi b(n - 1, 0);
  mp[b] = 1;
  long long ans = 0;
  for (char c: s) {
    ++cnt[c - 'a'];
    for (int i = 1; i < n; ++i) {
      b[i - 1] = cnt[a[i]] - cnt[a[i - 1]];
    }
    ans += mp[b];
    ++mp[b];
  }
  cout << ans;
  return 0;
}
