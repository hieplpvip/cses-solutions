#include <bits/stdc++.h>
using namespace std;
const int N = 205, INF = 1e9;

int n, c[N][N], u[N], v[N], p[N], d[N], trace[N];
bool used[N];

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> c[i][j];
    }
  }
  for (int i = 1; i <= n; ++i) {
    p[0] = i;
    int j0 = 0;
    fill(d + 1, d + 1 + n, INF);
    fill(used + 1, used + 1 + n, false);
    do {
      used[j0] = true;
      int i0 = p[j0], delta = INF, j1;
      for (int j = 1; j <= n; ++j) {
        if (!used[j]) {
          int cur = c[i0][j] - u[i0] - v[j];
          if (cur < d[j]) {
            d[j] = cur;
            trace[j] = j0;
          }
          if (d[j] < delta) {
            delta = d[j];
            j1 = j;
          }
        }
      }
      for (int j = 0; j <= n; ++j) {
        if (used[j]) {
          u[p[j]] += delta;
          v[j] -= delta;
        } else {
          d[j] -= delta;
        }
      }
      j0 = j1;
    } while (p[j0]);
    do {
      int j1 = trace[j0];
      p[j0] = p[j1];
      j0 = j1;
    } while (j0);
  }
  cout << -v[0] << "\n";
  for (int i = 1; i <= n; ++i) {
    cout << p[i] << " " << i << "\n";
  }
  return 0;
}
