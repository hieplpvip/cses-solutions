#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, m, x[N], pos[N];

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
    pos[x[i]] = i;
  }
  pos[0] = 0;
  pos[n + 1] = n + 1;
  int ans = 1;
  for (int i = 1; i <= n; ++i) {
    if (pos[i] < pos[i - 1]) ++ans;
  }
  while (m--) {
    int a, b; cin >> a >> b;
    if (x[a] > x[b]) swap(a, b);
    ans -= pos[x[a]] < pos[x[a] - 1];
    ans -= pos[x[a] + 1] < pos[x[a]];
    if (x[a] + 1 != x[b]) ans -= pos[x[b]] < pos[x[b] - 1];
    ans -= pos[x[b] + 1] < pos[x[b]];
    swap(a, b);
    swap(x[a], x[b]);
    swap(pos[x[a]], pos[x[b]]);
    ans += pos[x[a]] < pos[x[a] - 1];
    ans += pos[x[a] + 1] < pos[x[a]];
    if (x[a] + 1 != x[b]) ans += pos[x[b]] < pos[x[b] - 1];
    ans += pos[x[b] + 1] < pos[x[b]];
    cout << ans << "\n";
  }
  return 0;
}
