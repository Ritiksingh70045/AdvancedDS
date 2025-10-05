#include <bits/stdc++.h>
using namespace std;

class BIT
{
  vector<long long> bit;
  int n;
  public : 
  BIT(int size)
  {
    n = size;
    bit.assign(n + 2, 0); // 1-indexed
  }

  void update(int idx, long long val)
  {
    while (idx <= n)
    {
      bit[idx] += val;
      idx += idx & -idx;
    }
  }

  long long query(int idx)
  {
    long long res = 0;
    while (idx > 0)
    {
      res += bit[idx];
      idx -= idx & -idx;
    }
    return res;
  }

  // range update l..r by val using Difference Array
  void range_add(int l, int r, long long val)
  {
    update(l, val);
    update(r + 1, -val);
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;
  vector<long long> arr(n + 1); // 1-based indexing
  for (int i = 1; i <= n; i++)
    cin >> arr[i];

  BIT bit(n);

  while (q--)
  {
    int type;
    cin >> type;
    if (type == 1)
    {
      int l, r;
      long long u;
      cin >> l >> r >> u;
      bit.range_add(l, r, u);
    }
    else
    {
      int k;
      cin >> k;
      long long ans = arr[k] + bit.query(k);
      cout << ans << "\n";
    }
  }
}
