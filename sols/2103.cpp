#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

struct Node {
  int len, link, cnt, next[26];
};

int k, sz, last;
string s;
Node sa[N];
vector<pair<int, int>> order;

void sa_init() {
  sa[0].len = 0;
  sa[0].link = -1;
  sz = 1; last = 0;
}

void sa_extend(int c) {
  int cur = sz++, p;
  sa[cur].len = sa[last].len + 1;
  sa[cur].cnt = 1;
  order.emplace_back(sa[cur].len, cur);
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
      sa[clone].cnt = 0;
      memcpy(sa[clone].next, sa[q].next, sizeof(sa[q].next));
      order.emplace_back(sa[clone].len, clone);
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
  cin >> s >> k;
  sa_init();
  for (char c: s) {
    sa_extend(c - 'a');
  }
  sort(order.begin(), order.end(), greater<pair<int, int>>());
  for (auto [len, p]: order) {
    sa[sa[p].link].cnt += sa[p].cnt;
  }
  while (k--) {
    string p; cin >> p;
    int cur = 0;
    bool found = true;
    for (char c: p) {
      int cc = c - 'a';
      if (!sa[cur].next[cc]) {
        found = false;
        break;
      }
      cur = sa[cur].next[cc];
    }
    cout << (found ? sa[cur].cnt : 0) << "\n";
  }
  return 0;
}
