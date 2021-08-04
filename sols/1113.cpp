#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6;

string s;
int n, start, nxt[N];
vector<int> g[27];

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> s;
  n = s.length();
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == '#') {
      g[0].emplace_back(i);
      start = i;
    } else {
      g[s[i] - 'a' + 1].emplace_back(i);
    }
  }
  for (int i = 0, j = 0; i < n; ++i) {
    while (g[j].empty()) ++j;
    nxt[i] = g[j].back();
    g[j].pop_back();
  }
  for (int cur = nxt[start]; cur != start; cur = nxt[cur]) {
    cout << s[cur];
  }
  return 0;
}
