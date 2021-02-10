#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

ll powmod(ll a, ll b) {
  ll res = 1;
  for (; b; b >>= 1, (a *= a) %= MOD) {
    if (b & 1) (res *= a) %= MOD;
  }
  return res;
}

int main() {
  int n; cin >> n;
  cout << powmod(2, n) << "\n";
  return 0;
}
