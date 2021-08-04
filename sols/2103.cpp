#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int k, sz, last, len[N], link[N], cnt[N], nxt[N][26];
string s;
vector<pair<int, int>> order;

void sa_init() {
  len[0] = 0;
  link[0] = -1;
  sz = 1; last = 0;
}

void sa_extend(int c) {
  int cur = sz++, p;
  len[cur] = len[last] + 1;
  cnt[cur] = 1;
  order.emplace_back(len[cur], cur);
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
      cnt[clone] = 0;
      memcpy(nxt[clone], nxt[q], sizeof(nxt[q]));
      order.emplace_back(len[clone], clone);
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
  cin >> s >> k;
  sa_init();
  for (char c: s) {
    sa_extend(c - 'a');
  }
  sort(order.begin(), order.end(), greater<pair<int, int>>());
  for (auto [len, p]: order) {
    cnt[link[p]] += cnt[p];
  }
  while (k--) {
    string p; cin >> p;
    int cur = 0;
    bool found = true;
    for (char c: p) {
      int cc = c - 'a';
      if (!nxt[cur][cc]) {
        found = false;
        break;
      }
      cur = nxt[cur][cc];
    }
    cout << (found ? cnt[cur] : 0) << "\n";
  }
  return 0;
}
