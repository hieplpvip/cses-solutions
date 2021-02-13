#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int N = 4e5 + 5;

struct Project {
  int l, r, p;
};
inline bool operator <(const Project &a, const Project &b) {
  return a.r < b.r;
}

int n, m;
ll fen[N], f[N];
vector<int> cords;
vector<Project> A;

void update(int p, ll v) {
  for (; p <= m; p += p & -p) {
    fen[p] = max(fen[p], v);
  }
}

ll get(int p) {
  ll v = 0;
  for (; p >= 1; p -= p & -p) {
    v = max(v, fen[p]);
  }
  return v;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 1, l, r, p; i <= n; ++i) {
    cin >> l >> r >> p;
    A.push_back({l, r, p});
    cords.emplace_back(l);
    cords.emplace_back(r);
  }
  sort(all(A));
  sort(all(cords));
  cords.resize(unique(all(cords)) - cords.begin());
  m = cords.size();
  for (auto [l, r, p]: A) {
    int posl = lower_bound(all(cords), l) - cords.begin() + 1;
    int posr = lower_bound(all(cords), r) - cords.begin() + 1;
    f[posr] = get(posl - 1) + p;
    update(posr, f[posr]);
  }
  cout << get(m) << "\n";
  return 0;
}
