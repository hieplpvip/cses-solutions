#include <bits/stdc++.h>
using namespace std;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
const char d[] = {'L', 'R', 'U', 'D'};

string s;
int ans = 0;
bool vis[9][9];

void brute(int x, int y, int k) {
  if (vis[x - 1][y] && vis[x + 1][y] && !vis[x][y - 1] && !vis[x][y + 1]) return;
  if (!vis[x - 1][y] && !vis[x + 1][y] && vis[x][y - 1] && vis[x][y + 1]) return;
  if (x == 7 && y == 1) {
    if (k == 48) ++ans;
    return;
  }
  vis[x][y] = true;
  if (s[k] == '?') {
    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (1 <= nx && nx <= 7 && 1 <= ny && ny <= 7 && !vis[nx][ny]) {
        brute(nx, ny, k + 1);
      }
    }
  } else {
    for (int i = 0; i < 4; ++i) {
      if (s[k] == d[i]) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (1 <= nx && nx <= 7 && 1 <= ny && ny <= 7 && !vis[nx][ny]) {
          brute(nx, ny, k + 1);
        }
        break;
      }
    }
  }
  vis[x][y] = false;
}

int main() {
  cin >> s;
  for (int i = 0; i <= 8; ++i) {
    vis[0][i] = vis[8][i] = vis[i][0] = vis[i][8] = true;
  }
  brute(1, 1, 0);
  cout << ans << "\n";
  return 0;
}
