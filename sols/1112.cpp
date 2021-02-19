#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const int N = 1001, M = 101;

int n, m, pi[M], nxt[M][26];
ll f[N][M];
string s;

int main() {
  cin >> n >> s;
  m = s.length();
  for (int i = 1, j = 0; i < m; ++i) {
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) ++j;
    pi[i] = j;
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < 26; ++j) {
      if (i > 0 && s[i] != (char)('A' + j)) {
        nxt[i][j] = nxt[pi[i - 1]][j];
      } else {
        nxt[i][j] = i + (s[i] == (char)'A' + j);
      }
    }
  }
  f[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int k = 0; k < 26; ++k) {
        (f[i + 1][nxt[j][k]] += f[i][j]) %= MOD;
      }
    }
  }
  ll ans = 0, pw = 1;
  for (int i = n; i >= 1; --i) {
    (ans += f[i][m] * pw) %= MOD;
    (pw *= 26) %= MOD;
  }
  cout << ans << "\n";
  return 0;
}
