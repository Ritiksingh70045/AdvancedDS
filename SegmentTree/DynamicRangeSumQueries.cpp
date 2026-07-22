#include<bits/stdc++.h>
using namespace std;

class SGTree{
  vector<long long> seg;

  public : 
  SGTree(int n)
  {
    seg.resize(4*n + 1);
  }

  void build(int ind , int low , int high , int arr[])
  {
    if(low == high)
    {
      seg[ind] = arr[low];
      return;
    }

    int mid = (low+high)/2;
    build(2*ind + 1 , low , mid , arr);
    build(2*ind + 2 , mid+1 , high , arr);
    seg[ind] = seg[2*ind + 1] + seg[2*ind + 2];
    return;
  }

  long long query(int ind , int low , int high , int l , int r)
  {
    if((r<low) || (l>high))
    return 0;

    if((low>=l) && (high<=r))
    return seg[ind];

    int mid = (low+high)/2;
    long long left = query(2*ind+1 , low , mid , l ,r);
    long long right = query(2*ind + 2 , mid+1 , high , l , r);
    return (left + right);
  }

  void update(int ind , int low , int high , int val , int i)
  {
    if(low == high)
    {
      seg[ind] = val;
      return;
    }

    int mid = (low+high)/2;
    if(i<=mid)
    {
      update(2*ind + 1 , low , mid , val , i);
    }
    else
    {
      update(2*ind + 2 , mid + 1 , high , val , i);
    }

    seg[ind] = seg[2*ind + 1] + seg[2*ind + 2];
  }
};

int main()
{
  int n,q;
  cin>>n>>q;
  int arr[n];
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  SGTree sg(n);
  sg.build(0,0,n-1,arr);
  while(q--)
  {
    int a,b,c;
    cin>>a>>b>>c;
    if(a == 1)
    {
      sg.update(0,0,n-1,c,b-1);
    }
    else
    {
      long long ans = sg.query(0,0,n-1,b-1,c-1);
      cout<<ans<<'\n';
    }
  }
}