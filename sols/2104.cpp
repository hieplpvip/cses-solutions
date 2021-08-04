#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int sz, last, len[N], link[N], firstpos[N], nxt[N][26];

void sa_init() {
  len[0] = 0;
  link[0] = -1;
  sz = 1; last = 0;
}

void sa_extend(int c) {
  int cur = sz++, p;
  len[cur] = firstpos[cur] = len[last] + 1;
  for (p = last; p != -1 && !nxt[p][c]; p = link[p]) {
    nxt[p][c] = cur;
  }
  if (p == -1) {
    link[cur] = 0;
  } else {
    int q = nxt[p][c];
    if (len[p] + 1 == len[q]) {
      link[cur] = q;
    } else {
      int clone = sz++;
      len[clone] = len[p] + 1;
      link[clone] = link[q];
      firstpos[clone] = firstpos[q];
      memcpy(nxt[clone], nxt[q], sizeof(nxt[q]));
      for (; p != -1 && nxt[p][c] == q; p = link[p]) {
        nxt[p][c] = clone;
      }
      link[cur] = link[q] = clone;
    }
  }
  last = cur;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  string s; cin >> s;
  sa_init();
  for (char c: s) {
    sa_extend(c - 'a');
  }
  int k; cin >> k;
  while (k--) {
    string p; cin >> p;
    bool found = true;
    int cur = 0;
    for (char c: p) {
      int cc = c - 'a';
      if (!nxt[cur][cc]) {
        found = false;
        break;
      }
      cur = nxt[cur][cc];
    }
    cout << (found ? (firstpos[cur] - (int)p.size() + 1) : -1) << "\n";
  }
  return 0;
}
