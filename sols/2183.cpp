#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  ll res = 1;
  for (int i = 0; i < n && res >= a[i]; ++i) {
    res += a[i];
  }
  cout << res << "\n";
  return 0;
}
