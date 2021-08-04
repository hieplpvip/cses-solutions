#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  string s; cin >> s;
  int n = s.length();
  int per[n];
  iota(per, per + n, 0);
  vector<string> A;
  do {
    string t(n, ' ');
    for (int i = 0; i < n; ++i) {
      t[i] = s[per[i]];
    }
    A.push_back(t);
  } while (next_permutation(per, per + n));
  sort(A.begin(), A.end());
  A.resize(unique(A.begin(), A.end()) - A.begin());
  cout << A.size() << "\n";
  for (string &t: A) {
    cout << t << "\n";
  }
  return 0;
}
