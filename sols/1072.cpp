#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  for (int k = 1; k <= n; ++k) {
    cout << (1LL * k * k * (1LL * k * k - 1) / 2 - 4LL * (k - 1) * (k - 2)) << "\n";
  }
  return 0;
}
