#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  int code[1 << n];
  code[0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < (1 << i); ++j) {
      code[j + (1 << i)] = code[(1 << i) - 1 - j] | (1 << i);
    }
  }
  for (int i = 0; i < (1 << n); ++i) {
    for (int j = n - 1; j >= 0; --j) {
      cout << ((code[i] >> j) & 1);
    }
    cout << "\n";
  }
  return 0;
}
