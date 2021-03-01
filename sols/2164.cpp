#include <bits/stdc++.h>
using namespace std;

int find(int n, int k) {
  if (n == 1) {
    return 1;
  } else if (n & 1) {
    // 2, 4, ..., n - 1, 1
    return (k <= (n + 1) / 2) ? (2 * k % n) : (2 * find(n / 2, k - (n + 1) / 2) + 1);
  } else {
    // 2, 4, ..., n
    return (k <= n / 2) ? (2 * k) : (2 * find(n / 2, k - n / 2) - 1);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int q; cin >> q;
  while (q--) {
    int n, k;
    cin >> n >> k;
    cout << find(n, k) << "\n";
  }
  return 0;
}
