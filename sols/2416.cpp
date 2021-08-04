#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5, K = 20;

int n, q, jump[N][K];
ll x[N], sum[N], sjump[N][K];

// cost of range [a, b] is
// sum of (max(x[a -> i]) - x[i]) for i in range [a, b]

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
    sum[i] = sum[i - 1] + x[i];
  }
  memset(jump, -1, sizeof(jump));
  vector<int> A;
  for (int i = n; i >= 1; --i) {
    while (!A.empty() && x[i] >= x[A.back()]) A.pop_back();
    jump[i][0] = A.empty() ? (n + 1) : A.back();
    sjump[i][0] = x[i] * (jump[i][0] - i);
    A.push_back(i);
  }
  for (int k = 1; k < K; ++k) {
    for (int i = 1; i <= n; ++i) {
      if (jump[i][k - 1] != -1) {
        jump[i][k] = jump[jump[i][k - 1]][k - 1];
        sjump[i][k] = sjump[i][k - 1] + sjump[jump[i][k - 1]][k - 1];
      }
    }
  }
  while (q--) {
    int l, r; cin >> l >> r;
    ll ans = sum[l - 1] - sum[r];
    for (int k = K - 1; k >= 0; --k) {
      if (jump[l][k] != -1 && jump[l][k] <= r) {
        ans += sjump[l][k];
        l = jump[l][k];
      }
    }
    ans += x[l] * (r - l + 1);
    cout << ans << "\n";
  }
  return 0;
}
