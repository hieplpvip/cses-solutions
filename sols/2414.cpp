#include <bits/stdc++.h>
using namespace std;

int n, m, A[101];
vector<int> B;
multiset<int> st;

bool solve() {
  if (min({A[1], A[2], A[3]}) < 1 || max({A[1], A[2], A[3]}) > 1e9) {
    return false;
  }

  st.clear();
  for (int x: B) {
    st.emplace(x);
  }
  st.erase(st.find(A[1] + A[2]));
  st.erase(st.find(A[1] + A[3]));
  st.erase(st.find(A[2] + A[3]));

  for (int i = 4; i <= n; ++i) {
    A[i] = *st.begin() - A[1];
    if (A[i] < 1 || A[i] > 1e9) return false;
    for (int j = 1; j < i; ++j) {
      auto it = st.find(A[j] + A[i]);
      if (it == st.end()) return false;
      st.erase(it);
    }
  }

  vector<int> C;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      C.emplace_back(A[i] + A[j]);
    }
  }
  sort(C.begin(), C.end());
  return (C == B);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n;
  m = n * (n - 1) / 2;
  for (int i = 1, x; i <= m; ++i) {
    cin >> x;
    B.emplace_back(x);
  }
  sort(B.begin(), B.end());
  for (int i = 2; i < n; ++i) {
    A[2] = B[0] - B[1] + B[i];
    if (A[2] & 1) continue;
    A[2] /= 2;
    A[1] = B[0] - A[2];
    A[3] = B[i] - A[2];
    if (solve()) {
      for (int i = 1; i <= n; ++i) {
        cout << A[i] << " \n"[i == n];
      }
      return 0;
    }
  }
  assert(false);
  return 0;
}
