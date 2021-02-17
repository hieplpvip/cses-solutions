#include <bits/stdc++.h>
using namespace std;
const int N = 5005, MOD = 1e9 + 7;

struct Node {
  bool mark;
  Node* nxt[26];
};

int n, k, f[N];
string s;
Node* root;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> s;
  n = s.length();
  root = new Node();
  cin >> k;
  while (k--) {
    string t; cin >> t;
    reverse(t.begin(), t.end());
    Node* cur = root;
    for (char c: t) {
      int cc = c - 'a';
      if (!cur->nxt[cc]) {
        cur->nxt[cc] = new Node();
      }
      cur = cur->nxt[cc];
    }
    cur->mark = true;
  }
  f[0] = 1;
  for (int i = 1; i <= n; ++i) {
    Node* cur = root;
    for (int j = i - 1; j >= 0; --j) {
      if (!cur->nxt[s[j] - 'a']) break;
      cur = cur->nxt[s[j] - 'a'];
      if (cur->mark) {
        (f[i] += f[j]) %= MOD;
      }
    }
  }
  cout << f[n] << "\n";
  return 0;
}
