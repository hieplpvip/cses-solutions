#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  string s; cin >> s;
  int n = s.length();
  vector<int> d1(n), d2(n);
  for (int i = 0, l = 0, r = -1; i < n; ++i) {
    int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
    while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) ++k;
    d1[i] = k--;
    if (i + k > r) {
      l = i - k;
      r = i + k;
    }
  }
  for (int i = 0, l = 0, r = -1; i < n; ++i) {
    int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
    while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) ++k;
    d2[i] = k--;
    if (i + k > r) {
      l = i - k - 1;
      r = i + k;
    }
  }
  int len = 0, start = -1;
  for (int i = 0; i < n; ++i) {
    if (2 * d1[i] - 1 > len) {
      len = 2 * d1[i] - 1;
      start = i - d1[i] + 1;
    }
    if (2 * d2[i] > len) {
      len = 2 * d2[i];
      start = i - d2[i];
    }
  }
  cout << s.substr(start, len) << "\n";
  return 0;
}
