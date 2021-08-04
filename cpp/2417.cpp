#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int M = 1e6 + 6;

int cnt[M];

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  ll ans = 0;
  for (int a; n--;) {
    cin >> a;

    vector<int> prime;
    for (int j = 2; j * j <= a; ++j) {
      if (a % j == 0) {
        while (a % j == 0) a /= j;
        prime.emplace_back(j);
      }
    }
    if (a > 1) prime.emplace_back(a);

    int m = prime.size();
    for (int mk = 0; mk < (1 << m); ++mk) {
      int x = 1;
      for (int j = 0; j < m; ++j) {
        if ((mk >> j) & 1) x *= prime[j];
      }
      if (__builtin_popcount(mk) & 1) ans -= cnt[x];
      else ans += cnt[x];
      ++cnt[x];
    }
  }
  cout << ans << "\n";
  return 0;
}
