#include <bits/stdc++.h>
using namespace std;

int ans = 0;
char board[9][9];
bool col[9], diag1[15], diag2[15];

void brute(int r) {
  if (r == 9) {
    ++ans;
    return;
  }
  for (int c = 1; c <= 8; ++c) {
    if (board[r][c] == '*' || col[c] || diag1[r - c + 7] || diag2[r + c - 2]) continue;
    col[c] = diag1[r - c + 7] = diag2[r + c - 2] = true;
    brute(r + 1);
    col[c] = diag1[r - c + 7] = diag2[r + c - 2] = false;
  }
}

int main() {
  for (int i = 1; i <= 8; ++i) {
    for (int j = 1; j <= 8; ++j) {
      cin >> board[i][j];
    }
  }
  brute(1);
  cout << ans << "\n";
  return 0;
}
