#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 5;
int n;
ll p[N], sum[N];

ll calc(int mid) {
  return p[mid] * (2 * mid - n) + sum[n] - 2LL * sum[mid];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
  }
  sort(p + 1, p + 1 + n);
  for (int i = 1; i <= n; ++i) {
    sum[i] = sum[i - 1] + p[i];
  }
  if (n & 1) {
    cout << calc((n + 1) / 2) << "\n";
  } else {
    cout << min(calc(n / 2), calc(n / 2 + 1)) << "\n";
  }
  return 0;
}
