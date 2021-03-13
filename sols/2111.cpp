#include <bits/stdc++.h>
using namespace std;
using C = complex<double>;
using vd = vector<double>;

void fft(vector<C>& a) {
  int n = a.size(), L = 31 - __builtin_clz(n);
  static vector<complex<long double>> R(2, 1);
  static vector<C> rt(2, 1);
  for (static int k = 2; k < n; k *= 2) {
    R.resize(n); rt.resize(n);
    auto x = polar(1.0L, acos(-1.0L) / k);
    for (int i = k; i < 2 * k; ++i) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
  }
  vector<int> rev(n);
  for (int i = 0; i < n; ++i) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
  for (int i = 0; i < n; ++i) if (i < rev[i]) swap(a[i], a[rev[i]]);
  for (int k = 1; k < n; k *= 2) {
    for (int i = 0; i < n; i += 2 * k) {
      for (int j = 0; j < k; ++j) {
        C z = rt[j+k] * a[i+j+k];
        a[i + j + k] = a[i + j] - z;
        a[i + j] += z;
      }
    }
  }
}

vd conv(const vd& a, const vd& b) {
  if (a.empty() || b.empty()) return {};
  vd res(a.size() + b.size() - 1);
  int L = 32 - __builtin_clz(res.size()), n = 1 << L;
  vector<C> in(n), out(n);
  copy(a.begin(), a.end(), in.begin());
  for (int i = 0; i < (int)b.size(); ++i) in[i].imag(b[i]);
  fft(in);
  for (C& x: in) x *= x;
  for (int i = 0; i < n; ++i) out[i] = in[-i & (n - 1)] - conj(in[i]);
  fft(out);
  for (int i = 0; i < (int)res.size(); ++i) res[i] = imag(out[i]) / (4 * n);
  return res;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int k, n, m, x;
  cin >> k >> n >> m;
  vd a(k + 1), b(k + 1);
  while (n--) {
    cin >> x;
    a[x] += 1;
  }
  while (m--) {
    cin >> x;
    b[x] += 1;
  }
  vd ans = conv(a, b);
  for (int i = 2; i <= 2 * k; ++i) {
    cout << (long long)round(ans[i]) << " ";
  }
  return 0;
}
