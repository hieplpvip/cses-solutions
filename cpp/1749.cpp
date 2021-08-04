#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, x[N], fen[N];

void del(int p) {
  for (; p <= n; p += p & -p) {
    --fen[p];
  }
}

int find(int v) {
  int p = 0;
  for (int k = 20; k >= 0; --k) {
    if (p + (1 << k) <= n && fen[p + (1 << k)] < v) {
      v -= fen[p += (1 << k)];
    }
  }
  return p + 1;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
    fen[i] = i & -i;
  }
  for (int i = 1, p; i <= n; ++i) {
    cin >> p;
    int k = find(p); del(k);
    cout << x[k] << " \n"[i == n];
  }
  return 0;
}
