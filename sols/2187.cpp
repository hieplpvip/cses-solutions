#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const int N = 1e6 + 6;

ll fact[N], ifact[N];

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
  if (k < 0 || k > n) return 0;
  return fact[n] * ifact[k] % MOD * ifact[n - k] % MOD;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  fact[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = (fact[i - 1] * i) % MOD;
  }
  ifact[N - 1] = powmod(fact[N - 1], MOD - 2);
  for (int i = N - 1; i >= 1; --i) {
    ifact[i - 1] = (ifact[i] * i) % MOD;
  }
  int n;
  string s;
  cin >> n >> s;
  if (n & 1) {
    cout << "0\n";
    return 0;
  }
  n /= 2;
  int up = 0, down = 0;
  for (char c: s) {
    (c == '(') ? (++up) : (++down);
    if (up < down) {
      cout << "0\n";
      return 0;
    }
  }
  cout << (C(2 * n - up - down, n - up) - C(2 * n - up - down, n - 1 - up) + MOD) % MOD << "\n";
  return 0;
}
