#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, m, k, a[N], b[N], ans = 0;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int j = 1; j <= m; ++j) {
    cin >> b[j];
  }
  sort(a + 1, a + 1 + n);
  sort(b + 1, b + 1 + m);
  for (int i = 1, j = 1; i <= n && j <= m;) {
    if (abs(a[i] - b[j]) <= k) {
      ++i; ++j;
      ++ans;
    } else {
      if (a[i] < b[j] - k) {
        ++i;
      } else {
        ++j;
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
