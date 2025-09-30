#include <bits/stdc++.h>
using namespace std;

class SGTree
{
  vector<long long> seg, lazy;

public:
  SGTree(int n)
  {
    seg.resize(4*n + 1);
    lazy.resize(4*n + 1);
  }

  void build(int ind, int low, int high, int arr[])
  {
    if (low == high)
    {
      seg[ind] = arr[low];
      return;
    }
    int mid = (low + high) / 2;
    build(2 * ind + 1, low, mid, arr);
    build(2 * ind + 2, mid + 1, high, arr);
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    return;
  }

  void update(int ind, int low, int high, int l, int r, int val)
  {
    // update the previous remaining updates
    // and propogate downwards
    if (lazy[ind] != 0)
    {
      seg[ind] += (high - low + 1) * lazy[ind];
      // propogate the lazy update downwards
      // for the remaining nodes to get updated
      if (low != high)
      {
        lazy[2 * ind + 1] += lazy[ind];
        lazy[2 * ind + 2] += lazy[ind];
      }

      lazy[ind] = 0;
    }

    // no overlap
    // we don't do anything and return
    // low high l r or l r low high
    if (high < l || r < low)
    {
      return;
    }

    // complete overlap
    // l low high r
    if (low >= l && high <= r)
    {
      seg[ind] += (high - low + 1) * val;
      // if a leaf node, it will have childrens
      if (low != high)
      {
        lazy[2 * ind + 1] += val;
        lazy[2 * ind + 2] += val;
      }
      return;
    }
    // last case has to be no overlap case
    int mid = (low + high) >> 1;
    update(2 * ind + 1, low, mid, l, r, val);
    update(2 * ind + 2, mid + 1, high, l, r, val);
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
  }

  long long query(int ind, int low, int high, int l, int r)
  {
    // update if any updates are remaining
    // as the node will stay fresh and updated
    if (lazy[ind] != 0)
    {
      seg[ind] += (high - low + 1) * lazy[ind];
      // propogate the lazy update downwards
      // for the remaining nodes to get updated
      if (low != high)
      {
        lazy[2 * ind + 1] += lazy[ind];
        lazy[2 * ind + 2] += lazy[ind];
      }

      lazy[ind] = 0;
    }

    // no overlap return 0;
    if (high < l or r < low)
    {
      return 0;
    }

    // complete overlap
    if (low >= l && high <= r)
      return seg[ind];

    int mid = (low + high) >> 1;
    long long left = query(2 * ind + 1, low, mid, l, r);
    long long right = query(2 * ind + 2, mid + 1, high, l, r);
    return left + right;
  }
};

int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
  cin>>arr[i];
  SGTree sg(n);
  sg.build(0,0,n-1,arr);
  int q;
  cin>>q;
  while(q--)
  {
    int a,b,c,d;
    cin>>a;
    if(a == 1)
    {
      cin>>b>>c>>d;
      sg.update(0,0,n-1,b-1,c-1,d);
    }
    else
    {
      cin>>b>>c;
      long long ans = sg.query(0,0,n-1,b-1,c-1);
      cout<<ans<<'\n';
    }
  }
}