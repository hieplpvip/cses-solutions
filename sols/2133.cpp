#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
const int N = 1e5 + 5;

int n, m, k, par[N], ans[N], cntcmp;
map<ii, int> mp;
vector<ii> st[N << 2];
vector<tuple<int, int, int>> track;

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

void add(int id, int l, int r, int u, int v, ii e) {
  if (v < l || r < u) return;
  if (u <= l && r <= v) {
    st[id].push_back(e);
    return;
  }
  int mid = (l + r) >> 1;
  add(id << 1, l, mid, u, v, e);
  add(id << 1 | 1, mid + 1, r, u, v, e);
}

void calc(int id, int l, int r) {
  for (auto [u, v]: st[id]) {
    join(u, v);
  }
  if (l == r) {
    ans[l] = cntcmp;
  } else {
    int mid = (l + r) >> 1;
    calc(id << 1, l, mid);
    calc(id << 1 | 1, mid + 1, r);
  }
  for (size_t i = 0; i < st[id].size(); ++i) {
    rollback();
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m >> k;
  for (int u, v; m--;) {
    cin >> u >> v;
    if (u > v) swap(u, v);
    mp[{u, v}] = 1;
  }
  for (int i = 1, t, u, v; i <= k; ++i) {
    cin >> t >> u >> v;
    if (u > v) swap(u, v);
    if (t == 1) {
      mp[{u, v}] = i + 1;
    } else {
      add(1, 1, k + 1, mp[{u, v}], i, {u, v});
      mp.erase({u, v});
    }
  }
  for (auto [e, t]: mp) {
    add(1, 1, k + 1, t, k + 1, e);
  }
  fill(par + 1, par + 1 + n, -1);
  cntcmp = n;
  calc(1, 1, k + 1);
  for (int i = 1; i <= k + 1; ++i) {
    cout << ans[i] << " \n"[i == k + 1];
  }
  return 0;
}
