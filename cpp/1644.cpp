#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;

int n, a, b;
ll x[N], sum[N], ans = LLONG_MIN;
deque<ll> dq;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> a >> b;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
    sum[i] = sum[i - 1] + x[i];
  }
  for (int i = a; i <= n; ++i) {
    if (!dq.empty() && dq.front() < i - b) {
      dq.pop_front();
    }
    while (!dq.empty() && sum[i - a] <= sum[dq.back()]) {
      dq.pop_back();
    }
    dq.emplace_back(i - a);
    ans = max(ans, sum[i] - sum[dq.front()]);
  }
  cout << ans << "\n";
  return 0;
}
