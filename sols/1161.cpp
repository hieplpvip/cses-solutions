#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  priority_queue<int, vector<int>, greater<int>> q;
  int x, n; cin >> x >> n;
  for (int i = 1, d; i <= n; ++i) {
    cin >> d;
    q.emplace(d);
  }
  long long cost = 0;
  while (q.size() > 1) {
    int u = q.top(); q.pop();
    int v = q.top(); q.pop();
    q.emplace(u + v);
    cost += u + v;
  }
  cout << cost << "\n";
  return 0;
}
