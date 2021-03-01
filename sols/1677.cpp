#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, m, k, par[N], cntcmp;
bool mark[N];
vector<pair<int, int>> down;
vector<tuple<int, int, int>> track;
map<pair<int, int>, int> mp;

int root(int v) {
  return (par[v] < 0) ? v : root(par[v]);
}

void join(int x, int y) {
  if ((x = root(x)) == (y = root(y))) {
    track.emplace_back(0, 0, 0);
    return;
  }
  if (par[x] > par[y]) swap(x, y);
  track.emplace_back(x, y, par[y]);
  par[x] += par[y];
  par[y] = x;
  --cntcmp;
}

void rollback() {
  auto [x, y, t] = track.back();
  track.pop_back();
  if (x) {
    par[x] -= t;
    par[y] = t;
    ++cntcmp;
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    if (u > v) swap(u, v);
    mp[{u, v}] = i;
  }
  for (int i = 1, u, v; i <= k; ++i) {
    cin >> u >> v;
    if (u > v) swap(u, v);
    down.emplace_back(u, v);
    mark[mp[{u, v}]] = true;
  }
  reverse(down.begin(), down.end());
  fill(par + 1, par + 1 + n, -1);
  cntcmp = n;
  for (auto [e, i]: mp) {
    if (!mark[i]) {
      join(e.first, e.second);
    }
  }
  for (auto [u, v]: down) {
    join(u, v);
  }
  while (k--) {
    rollback();
    cout << cntcmp << "\n";
  }
  return 0;
}
