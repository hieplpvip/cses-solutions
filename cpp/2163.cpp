#include <bits/stdc++.h>
using namespace std;

const int N = 5e5;
int n, k, fen[N];

void add(int p, int v) {
  for (; p < N; p += p & -p) fen[p] += v;
}

int sum(int p) {
  int v = 0;
  for (; p > 0; p -= p & -p) v += fen[p];
  return v;
}

int search(int v) {
  int p = 0;
  for (int i = 20; i >= 0; --i) {
    if (p + (1 << i) < N && fen[p + (1 << i)] < v) {
      p += (1 << i);
      v -= fen[p];
    }
  }
  return p + 1;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> k; ++k;
  for (int i = 1; i <= n; ++i) {
    add(i, 1);
    add(i + n, 1);
  }
  for (int i = n, last = 0; i >= 1; --i) {
    int h = (k - 1) % i + 1;
    last = search(sum(last) + h);
    if (last > n) last -= n;
    cout << last << " ";
    add(last, -1);
    add(last + n, -1);
  }
  cout << "\n";
  return 0;
}
