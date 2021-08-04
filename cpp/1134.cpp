#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  vector<int> code(n - 2), deg(n + 1, 1);
  for (int i = 0; i < n - 2; ++i) {
    cin >> code[i];
    ++deg[code[i]];
  }
  int p = 1;
  while (deg[p] != 1) ++p;
  int leaf = p;
  for (int c: code) {
    cout << c << " " << leaf << "\n";
    if (--deg[c] == 1 && c < p) {
      leaf = c;
    } else {
      ++p;
      while (deg[p] != 1) ++p;
      leaf = p;
    }
  }
  cout << n << " " << leaf << "\n";
  return 0;
}
