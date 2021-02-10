#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5, M = 1e6 + 6;

int n, a[N], cnt[M];
ll ans = 0;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    for (int j = 1; j * j <= a[i]; ++j) {
      if (a[i] % j == 0) {
        ++cnt[j];
        if ((a[i] / j) != j) ++cnt[a[i] / j];
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i] == 1) {
      ans += n - 1;
      continue;
    }

    vector<int> prime;
    for (int j = 2; j * j <= a[i]; ++j) {
      if (a[i] % j == 0) {
        while (a[i] % j == 0) a[i] /= j;
        prime.emplace_back(j);
      }
    }
    if (a[i] > 1) prime.emplace_back(a[i]);

    int m = prime.size(), tmp = 0;
    for (int mk = 1; mk < (1 << m); ++mk) {
      int x = 1;
      for (int j = 0; j < m; ++j) {
        if ((mk >> j) & 1) x *= prime[j];
      }
      if (__builtin_popcount(mk) & 1) tmp += cnt[x];
      else tmp -= cnt[x];
    }
    ans += n - tmp;
  }
  cout << (ans / 2) << "\n";
  return 0;
}
