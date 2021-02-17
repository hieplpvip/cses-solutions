#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t; cin >> s >> t;
  string A = t + "#" + s;
  int n = A.length();
  vector<int> pi(n);
  for (int i = 1, j = 0; i < n; ++i) {
    while (j > 0 && A[i] != A[j]) j = pi[j - 1];
    if (A[i] == A[j]) ++j;
    pi[i] = j;
  }
  int ans = 0;
  for (int i = t.length(); i < n; ++i) {
    if (pi[i] == (int)t.length()) {
      ++ans;
    }
  }
  cout << ans << "\n";
  return 0;
}
