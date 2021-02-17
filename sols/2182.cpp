#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const int N = 1e5 + 5;

int n;
ll p[N], k[N], pre[N], suf[N];

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
  cin >> n;
  pre[0] = 1;
  for (int i = 1; i <= n; ++i) {
    cin >> p[i] >> k[i];
    pre[i] = (pre[i - 1] * (k[i] + 1)) % (MOD - 1);
  }
  suf[n + 1] = 1;
  for (int i = n; i >= 1; --i) {
    suf[i] = (suf[i + 1] * (k[i] + 1)) % (MOD - 1);
  }
  ll num = 1, sum = 1, prod = 1;
  for (int i = 1; i <= n; ++i) {
    (num *= k[i] + 1) %= MOD;
    (sum *= powmod(p[i], k[i] + 1) - 1) %= MOD;
    (sum *= powmod(p[i] - 1, MOD - 2)) %= MOD;
    ll tmp = (pre[i - 1] * suf[i + 1]) % (MOD - 1);
    (tmp *= (k[i] * (k[i] + 1) / 2) % (MOD - 1)) %= (MOD - 1);
    (prod *= powmod(p[i], tmp)) %= MOD;
  }
  if (sum < 0) sum += MOD;
  cout << num << " " << sum << " " << prod << "\n";
  return 0;
}
