#include <bits/stdc++.h>
using namespace std;

int main() {
  string s; cin >> s;
  int n = s.length();
  int ans = 1;
  for (int i = 1, cnt = 1; i < n; ++i) {
    if (s[i] != s[i - 1]) cnt = 0;
    ans = max(ans, ++cnt);
  }
  cout << ans << "\n";
  return 0;
}
