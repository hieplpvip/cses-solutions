#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define emb emplace_back
using pii = pair<int, int>;
using vi = vector<int>;

int findCentroid(vector<vi>& g, int u, int p, vi& c) {
  bool ok = true; int nChild = 1;
  for (int v: g[u]) if (v != p) {
    int t = findCentroid(g, v, u, c);
    if (t > (sz(g) >> 1)) ok = false;
    nChild += t;
  }
  if (ok && (sz(g) - nChild) <= (sz(g) >> 1)) c.emb(u);
  return nChild;
}

int setLevels(vector<vi>& g, int u, int d, vi& p, vector<vi>& lv) {
  lv[d].emb(u); int mx = d;
  for (int v: g[u]) {
    if (v != p[u]) {
      p[v] = u;
      mx = max(mx, setLevels(g, v, d + 1, p, lv));
    }
  }
  return mx;
}

bool checkIsomorphic(vector<vi> g[2]) {
  if (g[0].size() != g[1].size()) return false;
  vi c1, c2;
  findCentroid(g[0], 1, -1, c1);
  findCentroid(g[1], 1, -1, c2);
  if (c1.size() != c2.size()) return false;
  vi p[2], la[2]; vector<vi> lv[2];
  int r1 = c1[0], n = g[0].size();
  for (int r2: c2) {
    p[0].assign(n, -1); p[1].assign(n, -1);
    lv[0].assign(n, vi()); lv[1].assign(n, vi());
    int d1 = setLevels(g[0], r1, 0, p[0], lv[0]);
    int d2 = setLevels(g[1], r2, 0, p[1], lv[1]);
    if (d1 != d2) continue;
    la[0].assign(n, 0); la[1].assign(n, 0);
    bool ok = true;
    for (int curl = d1; curl >= 0; --curl) {
      vector<pair<vi, int>> order[2];
      rep(id,0,2) {
        for (int u: lv[id][curl]) {
          order[id].pb({vi(), u});
          for (int v: g[id][u]) {
            if (v != p[id][u]) {
              order[id].back().first.emb(la[id][v]);
            }
          }
        }
      }
      if (sz(order[0]) != sz(order[1])) { ok = false; break; };
      rep(i,0,sz(order[0])) {
        sort(all(order[0][i].first));
        sort(all(order[1][i].first));
      }
      sort(all(order[0])); sort(all(order[1]));
      int labelid = 0;
      rep(i,0,sz(order[0])) {
        if (order[0][i].first != order[1][i].first) {ok = false; break; }
        if (i && order[0][i].first != order[0][i - 1].first) ++labelid;
        la[0][order[0][i].second] = labelid;
        la[1][order[1][i].second] = labelid;
      }
    }
    if (ok) return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int T; cin >> T;
  while (T--) {
    int n; cin >> n;
    vector<vi> g[2];
    g[0].resize(n); g[1].resize(n);
    for (int i = 1, u, v; i < n; ++i) {
      cin >> u >> v; --u; --v;
      g[0][u].emb(v);
      g[0][v].emb(u);
    }
    for (int i = 1, u, v; i < n; ++i) {
      cin >> u >> v; --u; --v;
      g[1][u].emb(v);
      g[1][v].emb(u);
    }
    cout << (checkIsomorphic(g) ? "YES\n" : "NO\n");
  }
  return 0;
}
