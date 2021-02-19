#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

ll powmod(ll a, ll b) {
  ll res = 1;
  for (; b; b >>= 1, (a *= a) %= MOD) {
    if (b & 1) {
      (res *= a) %= MOD;
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  if (n & 1) {
    cout << "0\n";
    return 0;
  }
  n /= 2;
  ll fact_n = 1;
  for (int i = 1; i <= n; ++i) {
    (fact_n *= i) %= MOD;
  }
  ll fact_2n = fact_n;
  for (int i = n + 1; i <= 2 * n; ++i) {
    (fact_2n *= i) %= MOD;
  }
  ll ifact_n = powmod(fact_n, MOD - 2);
  ll res = fact_2n * ifact_n % MOD * ifact_n % MOD * powmod(n + 1, MOD - 2) % MOD;
  cout << res << "\n";
  return 0;
}
