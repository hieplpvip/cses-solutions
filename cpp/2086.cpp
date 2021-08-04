#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3005;

struct Line {
  ll a, b;
  ll calc(ll x) {
    return a * x + b;
  }
};

int n, k, seen;
ll sum[N], f[N][N];
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
  cin >> n >> k;
  for (int i = 1, x; i <= n; ++i) {
    cin >> x;
    sum[i] = sum[i - 1] + x;
    f[1][i] = sum[i] * sum[i];
  }
  for (int i = 2; i <= k; ++i) {
    seen = 0;
    A.clear();
    add_line(-2LL * sum[i - 1], f[i - 1][i - 1] + sum[i - 1] * sum[i - 1]);
    for (int j = i; j <= n; ++j) {
      f[i][j] = query(sum[j]) + sum[j] * sum[j];
      add_line(-2LL * sum[j], f[i - 1][j] + sum[j] * sum[j]);
    }
  }
  cout << f[k][n];
  return 0;
}
