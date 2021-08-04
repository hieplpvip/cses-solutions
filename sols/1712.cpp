#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll powmod(ll a, ll b, ll mod) {
  ll res = 1;
  for (; b; b >>= 1, (a *= a) %= mod) {
    if (b & 1) {
      (res *= a) %= mod;
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  while (n--) {
    ll a, b, c; cin >> a >> b >> c;
    ll x = powmod(b, c, 1e9 + 6);
    cout << powmod(a, x, 1e9 + 7) << "\n";
  }
  return 0;
}
