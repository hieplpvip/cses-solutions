#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, cur = 1, pre[N], in[N], pos[N];

void dfs(int l, int r) {
  int u = pre[cur], p = pos[u];
  if (l <= p - 1) {
    ++cur;
    dfs(l, p - 1);
  }
  if (p + 1 <= r) {
    ++cur;
    dfs(p + 1, r);
  }
  cout << u << " ";
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> pre[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> in[i];
    pos[in[i]] = i;
  }
  dfs(1, n);
  return 0;
}
