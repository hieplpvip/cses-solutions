#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, M = 1e6, K = 20;

int n, q, nxt[M + 6][K];
vector<pair<int, int>> movies;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> q;
  movies.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> movies[i].first >> movies[i].second;
  }
  sort(movies.begin(), movies.end());
  memset(nxt, -1, sizeof(nxt));
  for (int i = M, j = 1e9; i >= 1; --i) {
    while (!movies.empty() && movies.back().first >= i) {
      j = min(j, movies.back().second);
      movies.pop_back();
    }
    nxt[i][0] = j;
  }
  for (int k = 1; (1 << k) <= M; ++k) {
    for (int i = 1; i <= M; ++i) {
      if (nxt[i][k - 1] != -1 && nxt[i][k - 1] <= M) {
        nxt[i][k] = nxt[nxt[i][k - 1]][k - 1];
      }
    }
  }
  while (q--) {
    int a, b, ans = 0;
    cin >> a >> b;
    for (int k = K - 1; k >= 0; --k) {
      if (nxt[a][k] != -1 && nxt[a][k] <= b) {
        a = nxt[a][k];
        ans += (1 << k);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
