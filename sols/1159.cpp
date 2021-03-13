#include <bits/stdc++.h>
using namespace std;

int n, x, h[101], s[101], k[101], f[1001][100001];
vector<pair<int, int>> books;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> x;
  for (int i = 1; i <= n; ++i) cin >> h[i];
  for (int i = 1; i <= n; ++i) cin >> s[i];
  for (int i = 1; i <= n; ++i) cin >> k[i];
  for (int i = 1; i <= n; ++i) {
    int t = 0;
    for (int j = 1; t + j <= k[i]; j *= 2) {
      if (j * h[i] > x) break;
      t += j;
      books.emplace_back(j * h[i], j * s[i]);
    }
    if (t < k[i]) {
      t = k[i] - t;
      if (t * h[i] < x) {
        books.emplace_back(t * h[i], t * s[i]);
      }
    }
  }
  n = books.size();
  for (int i = 1; i <= n; ++i) {
    auto [w, v] = books[i - 1];
    for (int j = 1; j <= x; ++j) {
      if (w <= j) {
        f[i][j] = max(f[i - 1][j], f[i - 1][j - w] + v);
      } else {
        f[i][j] = f[i - 1][j];
      }
    }
  }
  cout << f[n][x];
  return 0;
}
