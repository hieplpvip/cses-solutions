#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  long long k;
  cin >> n >> k;
  for (int i = 1, j = n; i <= j;) {
    if (j - i <= k) {
      k -= j - i;
      cout << j-- << " ";
    } else {
      cout << i++ << " ";
    }
  }
  return 0;
}
