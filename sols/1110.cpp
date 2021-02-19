#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  string s; cin >> s;
  string t = s + s;
  int a = 0, n = s.length();
  for (int b = 0; b < n; ++b) {
    for (int k = 0; k < n; ++k) {
      if (a + k == b || t[a + k] < t[b + k]) {
        b += max(0, k - 1);
        break;
      }
      if (t[a + k] > t[b + k]) {
        a = b;
        break;
      }
    }
  }
  rotate(s.begin(), s.begin() + a, s.end());
  cout << s << "\n";
  return 0;
}
