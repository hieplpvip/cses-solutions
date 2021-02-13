#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
const int N = 6e5 + 5;

struct Query {
  char t;
  int a, b;
};

int n, q, m, p[N], fen[N];
vector<int> cords;
vector<Query> qq;

void add(int p, int v) {
  for (; p <= m; p += p & -p) {
    fen[p] += v;
  }
}

int get(int p) {
  int v = 0;
  for (; p >= 1; p -= p & -p) {
    v += fen[p];
  }
  return v;
}

int getpos(int x) {
  return lower_bound(all(cords), x) - cords.begin() + 1;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
    cords.emplace_back(p[i]);
  }
  for (int i = 1; i <= q; ++i) {
    char t; int a, b;
    cin >> t >> a >> b;
    qq.push_back({t, a, b});
    if (t == '?') {
      cords.emplace_back(a);
    }
    cords.emplace_back(b);
  }
  sort(all(cords));
  cords.resize(unique(all(cords)) - cords.begin());
  m = cords.size();
  for (int i = 1; i <= n; ++i) {
    add(getpos(p[i]), +1);
  }
  for (auto [t, a, b]: qq) {
    if (t == '!') {
      add(getpos(p[a]), -1);
      p[a] = b;
      add(getpos(p[a]), +1);
    } else {
      cout << (get(getpos(b)) - get(getpos(a) - 1)) << "\n";
    }
  }
  return 0;
}
