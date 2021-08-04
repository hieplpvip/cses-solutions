#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;

struct Line {
  ll a, b;
  ll calc(ll x) {
    return a * x + b;
  }
};

int n, seen;
ll s[N], f[N], dp[N];
vector<Line> A;

bool overlap(const Line &p1, const Line &p2, const Line &p3) {
  return (p3.b - p1.b) * (p1.a - p2.a) <= (p2.b - p1.b) * (p1.a - p3.a);
}

void add_line(ll a, ll b) {
  Line new_line = {a, b};
  while ((int)A.size() > seen + 1 && overlap(A[(int)A.size() - 2], A.back(), new_line)) A.pop_back();
  A.push_back(new_line);
}

ll query(ll x) {
  while (seen + 1 < (int)A.size() && A[seen].calc(x) >= A[seen + 1].calc(x)) ++seen;
  return A[seen].calc(x);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> f[0];
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
  }
  add_line(f[0], dp[0]);
  for (int i = 1; i <= n; ++i) {
    cin >> f[i];
    dp[i] = query(s[i]);
    add_line(f[i], dp[i]);
  }
  cout << dp[n];
  return 0;
}
