#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const int N = 1e6 + 6;

int n, k;
ll fact[N], ifact[N], f[N];

ll powmod(ll a, ll b) {
  ll res = 1;
  for (; b; b >>= 1, (a *= a) %= MOD) {
    if (b & 1) {
      (res *= a) %= MOD;
    }
  }
  return res;
}

ll C(int n, int k) {
  return fact[n] * ifact[k] % MOD * ifact[n - k] % MOD;
}

int main() {
  cin >> n >> k;
  fact[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fact[i] = (fact[i - 1] * i) % MOD;
  }
  ifact[n] = powmod(fact[n], MOD - 2);
  for (int i = n; i >= 1; --i) {
    ifact[i - 1] = (ifact[i] * i) % MOD;
  }
  ll ans = 0;
  for (int i = k, t = 0; i >= 1; --i, t ^= 1) {
    ll x = powmod(i, n) * C(k, i) % MOD;
    if (t) x = -x;
    (ans += x) %= MOD;
  }
  cout << (ans + MOD) % MOD;
  return 0;
}
