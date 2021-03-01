#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 6, D = 1e6 + 1;

int fen[N];

void add(int p, int v) {
  for (; p < N; p += p & -p) fen[p] += v;
}

int get(int p) {
  int v = 0;
  for (; p > 0; p -= p & -p) v += fen[p];
  return v;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  vector<tuple<int, int, int, int>> A;
  for (int x1, y1, x2, y2; n--;) {
    cin >> x1 >> y1 >> x2 >> y2;
    y1 += D; y2 += D;
    if (x1 == x2) {
      // vertical
      A.emplace_back(x1, 0, y1, y2);
    } else {
      // horizontal
      A.emplace_back(x1, -1, y1, y1);
      A.emplace_back(x2, +1, y1, y1);
    }
  }
  sort(A.begin(), A.end());
  long long ans = 0;
  for (auto [x, t, y1, y2]: A) {
    if (t == 0) {
      add(y1, +1);
      add(y2 + 1, -1);
    } else if (t == -1) {
      ans -= get(y1);
    } else {
      ans += get(y1);
    }
  }
  cout << ans;
  return 0;
}
