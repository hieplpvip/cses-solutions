#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, q, fen[N];

void add(int p, int v) {
  for (; p <= n; p += p & -p) fen[p] ^= v;
}

int get(int p) {
  int v = 0;
  for (; p >= 1; p -= p & -p) v ^= fen[p];
  return v;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> q;
  for (int i = 1, x; i <= n; ++i) {
    cin >> x;
    add(i, x);
  }
  while (q--) {
    int a, b; cin >> a >> b;
    cout << (get(b) ^ get(a - 1)) << "\n";
  }
  return 0;
}
