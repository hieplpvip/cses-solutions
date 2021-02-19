#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int sz, last, len[N], link[N], nxt[N][26];
long long cnt[N];

void sa_init() {
  len[0] = 0;
  link[0] = -1;
  sz = 1; last = 0;
}

void sa_extend(int c) {
  int cur = sz++, p;
  len[cur] = len[last] + 1;
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
  for (int i = 1; i < sz; ++i) {
    ++cnt[len[link[i]] + 1];
    --cnt[len[i] + 1];
  }
  for (int i = 1, n = s.length(); i <= n; ++i) {
    cnt[i] += cnt[i - 1];
    cout << cnt[i] << " \n"[i == n];
  }
  return 0;
}
