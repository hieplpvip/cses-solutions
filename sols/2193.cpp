#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }
  long long area = 0, B = 0, I;
  for (int i = 0, j = n - 1; i < n; j = i++) {
    area += 1LL * (x[i] - x[j]) * (y[i] + y[j]);
    B += gcd(abs(x[i] - x[j]), abs(y[i] - y[j]));
  }
  I = (abs(area) - B + 2) / 2;
  cout << I << " " << B;
  return 0;
}
