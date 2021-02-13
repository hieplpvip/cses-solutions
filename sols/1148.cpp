#include <bits/stdc++.h>
using namespace std;
const int N = 1005;

int n, m, R[N][N], U[N][N], D[N][N], ans[N][N];
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
      while (!A.empty() && R[i][j] < R[A.back()][j]) A.pop_back();
      U[i][j] = A.empty() ? 1 : (A.back() + 1);
      A.push_back(i);
    }
    A.clear();
    for (int i = n; i >= 1; --i) {
      while (!A.empty() && R[i][j] <= R[A.back()][j]) A.pop_back();
      D[i][j] = A.empty() ? n : (A.back() - 1);
      A.push_back(i);
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      // increase ans[i - Ui + 1] -> ans[Di - Ui + 1]
      //          ans[i - (Ui + 1) + 1] -> ans[Di - (Ui + 1) + 1]
      //          ...
      //          ans[i - i + 1] -> ans[Di - i + 1]
      ++ans[1][R[i][j]];
      --ans[i - U[i][j] + 2][R[i][j]];
      --ans[D[i][j] - i + 2][R[i][j]];
      ++ans[D[i][j] - U[i][j] + 3][R[i][j]];
    }
  }
  for (int j = 1; j <= m; ++j) {
    for (int i = 1; i <= n; ++i) {
      ans[i][j] += ans[i - 1][j];
    }
    for (int i = 1; i <= n; ++i) {
      ans[i][j] += ans[i - 1][j];
    }
  }
  for (int i = n; i >= 1; --i) {
    for (int j = m; j >= 2; --j) {
      ans[i][j - 1] += ans[i][j];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cout << ans[i][j] << " \n"[j == m];
    }
  }
  return 0;
}
