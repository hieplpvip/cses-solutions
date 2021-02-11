#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  vector<int> a(n);
  ll ans = 0;
  for (int i = 0, d; i < n; ++i) {
    cin >> a[i] >> d;
    ans += d;
  }
  sort(a.begin(), a.end());
  ll sum = 0;
  for (int x: a) {
    sum += x;
    ans -= sum;
  }
  cout << ans << "\n";
  return 0;
}
