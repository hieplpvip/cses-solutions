#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6;

int n, f[N];

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    f[i] = 1e9;
    for (char c: to_string(i)) {
      f[i] = min(f[i], f[i - (c - '0')] + 1);
    }
  }
  cout << f[n] << "\n";
  return 0;
}
