#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 5;
int n, q;
ll x[N], fen[N];

void add(int p, ll v) {
  for (; p <= n; p += p & -p) fen[p] += v;
}

ll get(int p) {
  ll v = 0;
  for (; p >= 1; p -= p & -p) v += fen[p];
  return v;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
  }
  while (q--) {
    int t; cin >> t;
    if (t == 1) {
      int a, b, u; cin >> a >> b >> u;
      add(a, u);
      add(b + 1, -u);
    } else {
      int k; cin >> k;
      cout << (x[k] + get(k)) << "\n";
    }
  }
  return 0;
}
