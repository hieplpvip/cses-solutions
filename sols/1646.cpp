#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;

int n, q;
ll sum[N];

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> q;
  for (int i = 1, x; i <= n; ++i) {
    cin >> x;
    sum[i] = sum[i - 1] + x;
  }
  while (q--) {
    int a, b; cin >> a >> b;
    cout << (sum[b] - sum[a - 1]) << "\n";
  }
  return 0;
}
