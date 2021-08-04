#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int cnt[26] = {};
  string s; cin >> s;
  for (char &c: s) {
    ++cnt[c - 'A'];
  }
  int cnt_odd = 0, ind_odd = -1;
  for (int i = 0; i < 26; ++i) {
    if (cnt[i] & 1) {
      ++cnt_odd;
      ind_odd = i;
    }
  }
  if (cnt_odd > 1) {
    cout << "NO SOLUTION\n";
  } else {
    for (int i = 0; i < 26; ++i) {
      if (cnt[i] > 0 && i != ind_odd) {
        for (int j = 1; j <= cnt[i] / 2; ++j) {
          cout << (char)('A' + i);
        }
      }
    }
    if (ind_odd != -1) {
      for (int j = 1; j <= cnt[ind_odd]; ++j) {
        cout << (char)('A' + ind_odd);
      }
    }
    for (int i = 25; i >= 0; --i) {
      if (cnt[i] > 0 && i != ind_odd) {
        for (int j = 1; j <= cnt[i] / 2; ++j) {
          cout << (char)('A' + i);
        }
      }
    }
    cout << "\n";
  }
  return 0;
}
