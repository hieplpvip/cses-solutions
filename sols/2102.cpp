#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

struct Node {
  int len, link, next[26];
};

int k, sz, last;
Node sa[N];
string s;

void sa_init() {
  sa[0].len = 0;
  sa[0].link = -1;
  last = 0;
  sz = 1;
}

void sa_extend(int c) {
  int cur = sz++, p;
  sa[cur].len = sa[last].len + 1;
  for (p = last; p != -1 && !sa[p].next[c]; p = sa[p].link) {
    sa[p].next[c] = cur;
  }
  if (p == -1) {
    sa[cur].link = 0;
  } else {
    int q = sa[p].next[c];
    if (sa[p].len + 1 == sa[q].len) {
      sa[cur].link = q;
    } else {
      int clone = sz++;
      sa[clone].len = sa[p].len + 1;
      sa[clone].link = sa[q].link;
      memcpy(sa[clone].next, sa[q].next, sizeof(sa[q].next));
      for (; p != -1 && sa[p].next[c] == q; p = sa[p].link) {
        sa[p].next[c] = clone;
      }
      sa[cur].link = sa[q].link = clone;
    }
  }
  last = cur;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> s;
  sa_init();
  for (char c: s) {
    sa_extend(c - 'a');
  }
  cin >> k;
  while (k--) {
    bool found = true;
    string p; cin >> p;
    int cur = 0;
    for (char c: p) {
      int cc = c - 'a';
      if (!sa[cur].next[cc]) {
        found = false;
        break;
      }
      cur = sa[cur].next[cc];
    }
    cout << (found ? "YES\n" : "NO\n");
  }
  return 0;
}
