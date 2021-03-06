#include <bits/stdc++.h>
using namespace std;

int n, cnt[26];
string s, t;

bool check(int c) {
  if (cnt[c] > n - cnt[c] + 1) return false;
  for (int i = 0; i < 26; ++i) {
    if (i != c && cnt[i] > n - cnt[i]) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> s;
  n = s.length();
  for (char c: s) {
    ++cnt[c - 'A'];
  }
  int last = -1;
  while (n) {
    char c = 0;
    for (int i = 0; i < 26; ++i) {
      if (i != last && cnt[i] && check(i)) {
        c = 'A' + i;
        last = i;
        --cnt[i];
        break;
      }
    }
    if (c == 0) {
      cout << "-1";
      return 0;
    }
    t += c; --n;
  }
  cout << t;
  return 0;
}
