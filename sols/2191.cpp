#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }
  long long area = 0;
  for (int i = 0, j = n - 1; i < n; j = i++) {
    area += 1LL * (x[i] - x[j]) * (y[i] + y[j]);
  }
  cout << abs(area);
  return 0;
}
