#include <bits/stdc++.h>
using namespace std;
const int N = 5005;

int n, m, f[N][N];
string s, t;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> s >> t;
  n = s.length();
  m = t.length();
  for (int i = 1; i <= n; ++i) {
    f[i][0] = i;
  }
  for (int j = 1; j <= m; ++j) {
    f[0][j] = j;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (s[i - 1] == t[j - 1]) {
        f[i][j] = f[i - 1][j - 1];
      } else {
        f[i][j] = min({f[i - 1][j], f[i][j - 1], f[i - 1][j - 1]}) + 1;
      }
    }
  }
  cout << f[n][m] << "\n";
  return 0;
}
