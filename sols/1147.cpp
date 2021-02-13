#include <bits/stdc++.h>
using namespace std;
const int N = 1005;

int n, m, R[N][N], U[N][N], D[N][N], ans = 0;
char mat[N][N];
vector<int> A;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> mat[i][j];
    }
    for (int j = m; j >= 1; --j) {
      if (mat[i][j] == '*') {
        R[i][j] = 0;
      } else {
        R[i][j] = R[i][j + 1] + 1;
      }
    }
  }
  for (int j = 1; j <= m; ++j) {
    A.clear();
    for (int i = 1; i <= n; ++i) {
      while (!A.empty() && R[i][j] <= R[A.back()][j]) A.pop_back();
      U[i][j] = A.empty() ? 1 : (A.back() + 1);
      A.push_back(i);
    }
    A.clear();
    for (int i = n; i >= 1; --i) {
      while (!A.empty() && R[i][j] <= R[A.back()][j]) A.pop_back();
      D[i][j] = A.empty() ? n : (A.back() - 1);
      A.push_back(i);
      ans = max(ans, R[i][j] * (D[i][j] - U[i][j] + 1));
    }
  }
  cout << ans << "\n";
  return 0;
}
