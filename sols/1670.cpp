#include <bits/stdc++.h>
using namespace std;

#define toint(x1, x2, x3, x4, x5, x6, x7, x8, x9) \
  (x1 * 100000000 + x2 * 10000000 + x3 * 1000000 + x4 * 100000 + x5 * 10000 + x6 * 1000 + x7 * 100 + x8 * 10 + x9)

unordered_set<int> st;
queue<pair<int, int>> q;

int main() {
  int start = 0;
  for (int i = 0, x; i < 9; ++i) {
    cin >> x;
    start = start * 10 + x;
  }
  st.emplace(start);
  q.emplace(start, 0);
  while (!q.empty()) {
    auto [u, du] = q.front(); q.pop();
    if (u == 123456789) {
      cout << du << "\n";
      return 0;
    }

    int x9 = u % 10; u /= 10;
    int x8 = u % 10; u /= 10;
    int x7 = u % 10; u /= 10;
    int x6 = u % 10; u /= 10;
    int x5 = u % 10; u /= 10;
    int x4 = u % 10; u /= 10;
    int x3 = u % 10; u /= 10;
    int x2 = u % 10; u /= 10;
    int x1 = u % 10;

    int v1 = toint(x2, x1, x3, x4, x5, x6, x7, x8, x9);
    if (!st.count(v1)) {
      st.emplace(v1);
      q.emplace(v1, du + 1);
    }

    int v2 = toint(x1, x3, x2, x4, x5, x6, x7, x8, x9);
    if (!st.count(v2)) {
      st.emplace(v2);
      q.emplace(v2, du + 1);
    }

    int v3 = toint(x1, x2, x3, x5, x4, x6, x7, x8, x9);
    if (!st.count(v3)) {
      st.emplace(v3);
      q.emplace(v3, du + 1);
    }

    int v4 = toint(x1, x2, x3, x4, x6, x5, x7, x8, x9);
    if (!st.count(v4)) {
      st.emplace(v4);
      q.emplace(v4, du + 1);
    }

    int v5 = toint(x1, x2, x3, x4, x5, x6, x8, x7, x9);
    if (!st.count(v5)) {
      st.emplace(v5);
      q.emplace(v5, du + 1);
    }

    int v6 = toint(x1, x2, x3, x4, x5, x6, x7, x9, x8);
    if (!st.count(v6)) {
      st.emplace(v6);
      q.emplace(v6, du + 1);
    }

    int v7 = toint(x4, x2, x3, x1, x5, x6, x7, x8, x9);
    if (!st.count(v7)) {
      st.emplace(v7);
      q.emplace(v7, du + 1);
    }

    int v8 = toint(x1, x2, x3, x7, x5, x6, x4, x8, x9);
    if (!st.count(v8)) {
      st.emplace(v8);
      q.emplace(v8, du + 1);
    }

    int v9 = toint(x1, x5, x3, x4, x2, x6, x7, x8, x9);
    if (!st.count(v9)) {
      st.emplace(v9);
      q.emplace(v9, du + 1);
    }

    int v10 = toint(x1, x2, x3, x4, x8, x6, x7, x5, x9);
    if (!st.count(v10)) {
      st.emplace(v10);
      q.emplace(v10, du + 1);
    }

    int v11 = toint(x1, x2, x6, x4, x5, x3, x7, x8, x9);
    if (!st.count(v11)) {
      st.emplace(v11);
      q.emplace(v11, du + 1);
    }

    int v12 = toint(x1, x2, x3, x4, x5, x9, x7, x8, x6);
    if (!st.count(v12)) {
      st.emplace(v12);
      q.emplace(v12, du + 1);
    }
  }
  assert(false);
  return 0;
}
