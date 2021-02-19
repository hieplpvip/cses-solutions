#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

struct Node {
  int len, link, next[26];
  long long cnt;
};

int sz, last;
Node sa[N];

void sa_init() {
  sa[0].len = 0;
  sa[0].link = -1;
  sz = 1; last = 0;
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

void dfs(int u) {
  sa[u].cnt = 1;
  for (int i = 0; i < 26; ++i) {
    if (!sa[u].next[i]) continue;
    int v = sa[u].next[i];
    if (!sa[v].cnt) dfs(v);
    sa[u].cnt += sa[v].cnt;
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  string s; cin >> s;
  sa_init();
  for (char c: s) {
    sa_extend(c - 'a');
  }
  dfs(0);
  cout << sa[0].cnt - 1 << "\n";
  return 0;
}
