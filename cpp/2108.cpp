#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;

int sz, last, len[N], link[N], nxt[N][26];
ll cnt[N];

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

void dfs(int u) {
  cnt[u] = 1;
  for (int i = 0; i < 26; ++i) {
    if (!nxt[u][i]) continue;
    int v = nxt[u][i];
    if (!cnt[v]) dfs(v);
    cnt[u] += cnt[v];
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
  ll k; cin >> k;
  int cur = 0;
  while (k > 0) {
    for (int i = 0; i < 26; ++i) {
      if (!nxt[cur][i]) continue;
      int v = nxt[cur][i];
      if (cnt[v] < k) {
        k -= cnt[v];
      } else {
        cout << (char)(i + 'a');
        --k; cur = v;
        break;
      }
    }
  }
  return 0;
}
