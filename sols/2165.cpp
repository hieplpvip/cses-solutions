#include <bits/stdc++.h>
#define emb emplace_back
using namespace std;

int n, k;
vector<int> A, B, C;

void moveAB() {
  if (B.empty() || (!A.empty() && A.back() < B.back())) {
    B.emb(A.back());
    A.pop_back();
    cout << "1 2\n";
  } else {
    A.emb(B.back());
    B.pop_back();
    cout << "2 1\n";
  }
}

void moveAC() {
  if (C.empty() || (!A.empty() && A.back() < C.back())) {
    C.emb(A.back());
    A.pop_back();
    cout << "1 3\n";
  } else {
    A.emb(C.back());
    C.pop_back();
    cout << "3 1\n";
  }
}

void moveBC() {
  if (C.empty() || (!B.empty() && B.back() < C.back())) {
    C.emb(B.back());
    B.pop_back();
    cout << "2 3\n";
  } else {
    B.emb(C.back());
    C.pop_back();
    cout << "3 2\n";
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n;
  k = (1 << n) - 1;
  for (int i = n; i >= 1; --i) {
    A.emb(i);
  }
  cout << k << "\n";
  if (n & 1) {
    for (int i = 1; i <= k; ++i) {
      if (i % 3 == 1) {
        moveAC();
      } else if (i % 3 == 2) {
        moveAB();
      } else {
        moveBC();
      }
    }
  } else {
    for (int i = 1; i <= k; ++i) {
      if (i % 3 == 1) {
        moveAB();
      } else if (i % 3 == 2) {
        moveAC();
      } else {
        moveBC();
      }
    }
  }
  return 0;
}
