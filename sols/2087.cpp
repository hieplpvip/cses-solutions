#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3005;

int n, k, x[N];
ll g[N][N], h[N][N];
vector<ll> fc, fp;

ll calc(int l, int r) {
  int mid = (l + r) >> 1;
  return g[l][mid] + h[r][mid + 1];
}

void compute(int l, int r, int optl, int optr) {
  if (l > r) return;
  int mid = (l + r) >> 1;
  pair<ll, int> best = {1e18, -1};
  for (int k = optl; k <= min(optr, mid - 1); ++k) {
    best = min(best, {fp[k] + calc(k, mid), k});
  }
  fc[mid] = best.first;
  compute(l, mid - 1, optl, best.second);
  compute(mid + 1, r, best.second, optr);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
  }
  for (int i = 1; i <= n; ++i) {
    g[i][i] = h[i][i] = 0;
    for (int j = i + 1; j <= n; ++j) {
      g[i][j] = g[i][j - 1] + 1LL * (j - i) * x[j];
    }
    for (int j = i - 1; j >= 1; --j) {
      h[i][j] = h[i][j + 1] + 1LL * (i - j) * x[j];
    }
  }
  fc.resize(n + 1);
  fp.resize(n + 1);
  for (int i = 1; i <= n; ++i) {
    fp[i] = h[i][1];
  }
  for (int i = 2; i <= k; ++i) {
    compute(i, n, i - 1, n);
    fc.swap(fp);
  }
  ll ans = 1e18;
  for (int i = k; i <= n; ++i) {
    ans = min(ans, fp[i] + g[i][n]);
  }
  cout << ans;
  return 0;
}
