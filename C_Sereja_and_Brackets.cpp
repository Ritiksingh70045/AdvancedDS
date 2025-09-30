#include <bits/stdc++.h>
using namespace std;

class info {
public:
  int open, close, full;

  info(int _open, int _close, int _full) {
    open = _open;
    close = _close;
    full = _full;
  }
  info() {
    open = 0;
    close = 0;
    full = 0;
  }
};

info merge(info left, info right) {
  int matched = min(left.open, right.close);
  info ans;
  ans.full = left.full + right.full + matched;
  ans.open = left.open + right.open - matched;
  ans.close = left.close + right.close - matched;
  return ans;
}

void build(int ind, int low, int high, string &s, info seg[]) {
  if (low == high) {
    if (s[low] == '(')
      seg[ind] = info(1, 0, 0);
    else
      seg[ind] = info(0, 1, 0);
    return;
  }

  int mid = (low + high) / 2;
  build(2 * ind + 1, low, mid, s, seg);
  build(2 * ind + 2, mid + 1, high, s, seg);
  seg[ind] = merge(seg[2 * ind + 1], seg[2 * ind + 2]);
}

info query(int ind, int low, int high, int l, int r, info seg[]) {
  if (r < low || high < l)
    return info();
  if (low >= l && high <= r)
    return seg[ind];
  int mid = (low + high) / 2;
  info left = query(2 * ind + 1, low, mid, l, r, seg);
  info right = query(2 * ind + 2, mid + 1, high, l, r, seg);
  return merge(left, right);
}

int main() {
  string s;
  cin >> s;
  int n = s.length();
  info seg[4 * n];
  build(0, 0, n - 1, s, seg);
  int q;
  cin >> q;  // <-- FIXED
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    info ans = query(0, 0, n - 1, l, r, seg);
    cout << ans.full * 2 << '\n';
  }
}
