#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, a[N], b[N], fen[N], inv[N], cnt;
map<int, int> mp;

void add(int p, int v) {
  for (; p < N; p += p & -p) {
    fen[p] += v;
  }
}

int get(int p) {
  int v = 0;
  for (; p > 0; p -= p & -p) {
    v += fen[p];
  }
  return v;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b + 1, b + 1 + n);
  for (int i = 1; i <= n; ++i) {
    mp[b[i]] = ++cnt;
  }
  for (int i = 1; i <= n; ++i) {
    inv[i] = i - 1 - get(mp[a[i]]);
    add(mp[a[i]], 1);
  }
  memset(fen, 0, sizeof(fen));
  long long ans = 0;
  for (int i = n; i >= 1; --i) {
    ans += min(inv[i], n - i - get(mp[a[i]]));
    add(mp[a[i]], 1);
  }
  cout << ans << "\n";
  return 0;
}
