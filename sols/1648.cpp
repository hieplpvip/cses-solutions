#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;

int n, q, x[N];
ll fen[N];

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
    add(i, x[i]);
  }
  while (q--) {
    int t, a, b; cin >> t >> a >> b;
    if (t == 1) {
      add(a, b - x[a]);
      x[a] = b;
    } else {
      cout << (get(b) - get(a - 1)) << "\n";
    }
  }
  return 0;
}
