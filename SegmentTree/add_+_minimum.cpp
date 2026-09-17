#include <bits/stdc++.h>
using namespace std;

class SGTree
{
private:
  vector<long long> seg, lazy;

public:
  SGTree(int n)
  {
    seg.resize(4 * n + 1);
    lazy.resize(4 * n + 1);
  }

  void build(int ind, int low, int high, vector<int> &arr)
  {
    if (low == high)
    {
      seg[ind] = arr[low];
      return;
    }

    int mid = (low + high) >> 1;

    build(2 * ind + 1, low, mid, arr);
    build(2 * ind + 2, mid + 1, high, arr);

    seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
  }

  void update(int ind, int low, int high,
              int l, int r, int val)
  {
    // Pending update
    if (lazy[ind] != 0)
    {
      seg[ind] += lazy[ind];

      if (low != high)
      {
        lazy[2 * ind + 1] += lazy[ind];
        lazy[2 * ind + 2] += lazy[ind];
      }

      lazy[ind] = 0;
    }

    // No overlap
    if (l > high || r < low)
    {
      return;
    }

    // Complete overlap
    if (low >= l && high <= r)
    {
      seg[ind] += val;

      if (low != high)
      {
        lazy[2 * ind + 1] += val;
        lazy[2 * ind + 2] += val;
      }

      return;
    }

    int mid = (low + high) >> 1;

    update(2 * ind + 1, low, mid, l, r, val);
    update(2 * ind + 2, mid + 1, high, l, r, val);

    seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
  }

  long long query(int ind, int low, int high,
                  int l, int r)
  {
    // Pending update
    if (lazy[ind] != 0)
    {
      seg[ind] += lazy[ind];

      if (low != high)
      {
        lazy[2 * ind + 1] += lazy[ind];
        lazy[2 * ind + 2] += lazy[ind];
      }

      lazy[ind] = 0;
    }

    // No overlap
    if (high < l || r < low)
      return LLONG_MAX;

    // Complete overlap
    if (low >= l && high <= r)
      return seg[ind];

    int mid = (low + high) >> 1;

    long long left =
        query(2 * ind + 1, low, mid, l, r);

    long long right =
        query(2 * ind + 2, mid + 1, high, l, r);

    return min(left, right);
  }
};

int main()
{
  vector<int> arr = {
      5, 3, 9, 2, 3, 99, 34, 65, 23, 89, 32};

  int n = arr.size();

  SGTree sg(n);

  sg.build(0, 0, n - 1, arr);

  cout << sg.query(0, 0, n - 1, 0, n - 1) << endl;

  sg.update(0, 0, n - 1, 0, 3, 10);

  cout << sg.query(0, 0, n - 1, 0, n - 1) << endl;
}