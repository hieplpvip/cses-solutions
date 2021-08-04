#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const int N = 2e6 + 6, M = 1005;

int n, m;
ll fact[N], invfact[N], f[M];
vector<pair<int, int>> trap;

ll powmod(ll a, ll b) {
  ll r = 1;
  for (; b; b >>= 1, (a *= a) %= MOD) {
    if (b & 1) {
      (r *= a) %= MOD;
    }
  }
  return r;
}

ll C(int n, int k) {
  return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  fact[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = fact[i - 1] * i % MOD;
  }
  invfact[N - 1] = powmod(fact[N - 1], MOD - 2);
  for (int i = N - 1; i >= 1; --i) {
    invfact[i - 1] = invfact[i] * i % MOD;
  }

  cin >> n >> m;
  trap.resize(m);
  for (auto& [x, y]: trap) {
    cin >> x >> y;
  }
  sort(trap.begin(), trap.end());

  ll ans = C(n + n - 2, n - 1);
  for (int i = 0; i < m; ++i) {
    auto [x, y] = trap[i];
    f[i] = C(x + y - 2, x - 1);
    for (int j = 0; j < i; ++j) {
      if (trap[j].second <= y) {
        f[i] -= f[j] * C(x - trap[j].first + y - trap[j].second, x - trap[j].first) % MOD;
        if (f[i] < 0) f[i] += MOD;
      }
    }
    (ans -= f[i] * C(n - x + n - y, n - x)) %= MOD;
    if (ans < 0) ans += MOD;
  }
  cout << ans << '\n';

  return 0;
}
