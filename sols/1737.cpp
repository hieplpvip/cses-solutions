#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;

struct Node {
  ll val;
  Node *left = nullptr, *right = nullptr;
};

int n, q, cnt, x[N];
Node* root[N];

Node* build(int l, int r) {
  Node *res = new Node;
  if (l == r) {
    res->val = x[l];
    return res;
  }
  int mid = (l + r) >> 1;
  res->left = build(l, mid);
  res->right = build(mid + 1, r);
  res->val = res->left->val + res->right->val;
  return res;
}

Node* update(Node* old, int l, int r, int u, int x) {
  Node *res = new Node;
  if (l == r) {
    res->val = x;
    return res;
  }
  int mid = (l + r) >> 1;
  if (u <= mid) {
    res->left = update(old->left, l, mid, u, x);
    res->right = old->right;
  } else {
    res->left = old->left;
    res->right = update(old->right, mid + 1, r, u, x);
  }
  res->val = res->left->val + res->right->val;
  return res;
}

ll get(Node* cur, int l, int r, int u, int v) {
  if (v < l || r < u) return 0;
  if (u <= l && r <= v) return cur->val;
  int mid = (l + r) >> 1;
  return get(cur->left, l, mid, u, v) + get(cur->right, mid + 1, r, u, v);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
  }
  root[cnt = 1] = build(1, n);
  while (q--) {
    int t, k; cin >> t >> k;
    if (t == 1) {
      int a, x; cin >> a >> x;
      root[k] = update(root[k], 1, n, a, x);
    } else if (t == 2) {
      int a, b; cin >> a >> b;
      cout << get(root[k], 1, n, a, b) << "\n";
    } else {
      root[++cnt] = root[k];
    }
  }
  return 0;
}
