#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, a[N], fen[N];
bool mark[N];

void add(int p) {
  for (; p > 0; p -= p & -p) {
    fen[p] += 1;
  }
}

int get(int p) {
  int res = 0;
  for (; p < N; p += p & -p) {
    res += fen[p];
  }
  return res;
}

void method1() {
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += get(a[i]);
    add(a[i]);
  }
  cout << ans << " ";
}

void method2() {
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (mark[i]) continue;
    int len = 0;
    for (int j = i; !mark[j]; j = a[j]) {
      mark[j] = true;
      ++len;
    }
    ans += len - 1;
  }
  cout << ans << " ";
}

void method3() {
  set<int> st;
  for (int i = 1; i <= n; ++i) {
    auto it = st.insert(a[i]).first;
    if (++it != st.end()) {
      st.erase(it);
    }
  }
  cout << n - st.size() << " ";
}

void method4() {
  int ans = n;
  for (int i = n; i >= 1; --i) {
    if (a[i] == ans) --ans;
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  method1();
  method2();
  method3();
  method4();
  return 0;
}
