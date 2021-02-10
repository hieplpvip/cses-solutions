#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, k, a[N];
map<int, int> cnt;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  long long ans = 0;
  for (int l = 1, r = 0, h = 0; l <= n; ++l) {
    if (l > 1) {
      if (--cnt[a[l - 1]] == 0) {
        --h;
      }
    }
    while (r < n) {
      if (h < k || (h == k && cnt[a[r + 1]] > 0)) {
        if (++cnt[a[++r]] == 1) {
          ++h;
        }
      } else {
        break;
      }
    }
    ans += (r - l + 1);
  }
  cout << ans << "\n";
  return 0;
}
