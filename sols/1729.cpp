#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6, K = 101;

int n, k, p[K];
bool f[N];

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= k; ++i) {
    cin >> p[i];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
      if (i >= p[j] && !f[i - p[j]]) {
        f[i] = true;
      }
    }
    cout << (f[i] ? 'W' : 'L');
  }
  return 0;
}
