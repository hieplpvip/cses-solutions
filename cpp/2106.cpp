#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int sz, last, len[N], link[N], nxt[N][26], firstpos[N];
long long cnt[N];
vector<pair<int, int>> order;

void sa_init() {
  len[0] = 0;
  link[0] = -1;
  sz = 1; last = 0;
}

void sa_extend(int c) {
  int cur = sz++, p;
  len[cur] = len[last] + 1;
  firstpos[cur] = len[cur] - 1;
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
      firstpos[clone] = firstpos[q];
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
  string s; cin >> s;
  sa_init();
  for (char c: s) {
    sa_extend(c - 'a');
  }
  sort(order.begin(), order.end());
  reverse(order.begin(), order.end());
  for (auto p: order) {
    cnt[link[p.second]] += cnt[p.second];
  }
  int mxlen = -1, start = -1;
  for (int i = 1; i < sz; ++i) {
    if (cnt[i] > 1 && len[i] > mxlen) {
      mxlen = len[i];
      start = firstpos[i] - len[i] + 1;
    }
  }
  if (mxlen == -1) {
    cout << "-1\n";
  } else {
    cout << s.substr(start, mxlen) << "\n";
  }
  return 0;
}
