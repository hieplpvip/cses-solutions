#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const int N = 5e5 + 5;

string s;
int n;
ll f[N], g[N];

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> s;
  n = s.length();
  f[0] = 1;
  for (int i = 1; i <= n; ++i) {
    int c = s[i - 1] - 'a';
    f[i] = (2LL * f[i - 1] - g[c]) % MOD;
    (g[c] += f[i] - f[i - 1]) %= MOD;
  }
  cout << (f[n] + MOD - 1) % MOD;
  return 0;
}
