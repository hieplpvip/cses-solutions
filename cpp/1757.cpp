#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, m, outdeg[N];
vector<int> radj[N], order;
priority_queue<int> q;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for (int i = 1, a, b; i <= m; ++i) {
    cin >> a >> b;
    radj[b].emplace_back(a);
    ++outdeg[a];
  }
  for (int i = 1; i <= n; ++i) {
    if (outdeg[i] == 0) {
      q.emplace(i);
    }
  }
  while (!q.empty()) {
    int u = q.top(); q.pop();
    order.emplace_back(u);
    for (int v: radj[u]) {
      if (--outdeg[v] == 0) {
        q.emplace(v);
      }
    }
  }
  reverse(order.begin(), order.end());
  for (int u: order) {
    cout << u << " ";
  }
  return 0;
}
