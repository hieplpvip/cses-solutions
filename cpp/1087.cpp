#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  string s; cin >> s;
  int n = s.length();
  int ca = 0, cc = 0, cg = 0, ct = 0;
  for (int i = 0; i < n;) {
    while (i < n && (!ca || !cc || !cg || !ct)) {
      if (s[i] == 'A') ++ca;
      else if (s[i] == 'C') ++cc;
      else if (s[i] == 'G') ++cg;
      else ++ct;
      ++i;
    }
    if (ca && cc && cg && ct) {
      cout << s[i - 1];
      ca = cc = cg = ct = 0;
    }
  }
  if (!ca) cout << 'A';
  else if (!cc) cout << 'C';
  else if (!cg) cout << 'G';
  else cout << 'T';
  return 0;
}
