#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  string s; cin >> s;
  int n = s.length();
  vector<int> pi(n), A;
  for (int i = 1, j = 0; i < n; ++i) {
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) ++j;
    pi[i] = j;
  }
  int j = pi[n - 1];
  while (j > 0) {
    A.emplace_back(j);
    j = pi[j - 1];
  }
  reverse(A.begin(), A.end());
  for (int len: A) {
    cout << len << " ";
  }
  cout << "\n";
  return 0;
}
