#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const int N = 1e6 + 6;

ll f[N];

int main() {
  int n; cin >> n;
  f[1] = 0;
  f[2] = 1;
  for (int i = 3; i <= n; ++i) {
    f[i] = (1LL * (i - 1) * (f[i - 1] + f[i - 2])) % MOD;
  }
  cout << f[n] << "\n";
  return 0;
}
