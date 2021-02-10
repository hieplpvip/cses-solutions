#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  int x = n % 4;
  int xor_n;
  if (x == 0) xor_n = n;
  else if (x == 1) xor_n = 1;
  else if (x == 2) xor_n = n + 1;
  else xor_n = 0;
  while (--n) {
    cin >> x;
    xor_n ^= x;
  }
  cout << xor_n << "\n";
  return 0;
}
