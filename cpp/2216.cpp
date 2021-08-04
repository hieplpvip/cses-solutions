#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, pos[N];

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 1, a; i <= n; ++i) {
    cin >> a;
    pos[a] = i;
  }
  int ans = 1;
  for (int i = 1; i <= n; ++i) {
    if (pos[i] < pos[i - 1]) ++ans;
  }
  cout << ans << "\n";
  return 0;
}
