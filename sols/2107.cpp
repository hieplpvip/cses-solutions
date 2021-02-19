#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  string s; cin >> s;
  int n = s.length();
  vector<int> z(n), pi(n);
  for (int i = 1, l = 0, r = 0, j = 0; i < n; ++i) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) ++j;
    pi[i] = j;
  }
  for (int i = 0; i < n; ++i) {
    cout << z[i] << " \n"[i == n - 1];
  }
  for (int i = 0; i < n; ++i) {
    cout << pi[i] << " \n"[i == n - 1];
  }
  return 0;
}
