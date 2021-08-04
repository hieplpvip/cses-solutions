#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  long long sum = 1LL * n * (n + 1) / 2;
  if (sum & 1) {
    cout << "NO\n";
  } else {
    sum /= 2;
    vector<int> p1, p2;
    for (int i = n; i >= 1; --i) {
      if (sum >= i) {
        sum -= i;
        p1.emplace_back(i);
      } else {
        p2.emplace_back(i);
      }
    }
    cout << "YES\n";
    cout << p1.size() << "\n";
    for (int &x: p1) cout << x << " ";
    cout << "\n" << p2.size() << "\n";
    for (int &x: p2) cout << x << " ";
    cout << "\n";
  }
  return 0;
}
