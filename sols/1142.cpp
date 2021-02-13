#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, k[N], L[N], R[N];
long long ans = 0;
vector<int> A;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> k[i];
    while (!A.empty() && k[i] <= k[A.back()]) A.pop_back();
    L[i] = A.empty() ? 1 : (A.back() + 1);
    A.push_back(i);
  }
  A.clear();
  for (int i = n; i >= 1; --i) {
    while (!A.empty() && k[i] <= k[A.back()]) A.pop_back();
    R[i] = A.empty() ? n : (A.back() - 1);
    A.push_back(i);
    ans = max(ans, 1LL * k[i] * (R[i] - L[i] + 1));
  }
  cout << ans << "\n";
  return 0;
}
