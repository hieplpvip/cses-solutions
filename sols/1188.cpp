#include <bits/stdc++.h>
using namespace std;

multiset<int> len;
set<int> bit0, bit1;
vector<int> pos0, pos1;

void remove(int x, set<int> &st) {
  auto it1 = st.upper_bound(x);
  auto it2 = --st.lower_bound(x);
  len.erase(len.find(*it1 - x - 1));
  len.erase(len.find(x - *it2 - 1));
  len.emplace(*it1 - *it2 - 1);
  st.erase(x);
}

void add(int x, set<int> &st) {
  auto it1 = st.upper_bound(x);
  auto it2 = it1; --it2;
  len.emplace(*it1 - x - 1);
  len.emplace(x - *it2 - 1);
  len.erase(len.find(*it1 - *it2 - 1));
  st.emplace(x);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  string s; cin >> s;
  int m; cin >> m;
  int n = s.length();
  pos0.emplace_back(-1);
  pos1.emplace_back(-1);
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      pos0.emplace_back(i);
    } else {
      pos1.emplace_back(i);
    }
  }
  pos0.emplace_back(n);
  pos1.emplace_back(n);
  for (int i = 0; i < (int)pos0.size(); ++i) {
    bit0.emplace(pos0[i]);
    if (i) len.emplace(pos0[i] - pos0[i - 1] - 1);
  }
  for (int i = 0; i < (int)pos1.size(); ++i) {
    bit1.emplace(pos1[i]);
    if (i) len.emplace(pos1[i] - pos1[i - 1] - 1);
  }
  while (m--) {
    int x; cin >> x; --x;
    if (s[x] == '0') {
      remove(x, bit0);
      add(x, bit1);
      s[x] = '1';
    } else {
      remove(x, bit1);
      add(x, bit0);
      s[x] = '0';
    }
    cout << *len.rbegin() << "\n";
  }
  return 0;
}
