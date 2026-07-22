#include<bits/stdc++.h>
using namespace std;

class SGTree{
  vector<int> seg;

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
    seg[ind] = min(seg[2*ind + 1] , seg[2*ind + 2]);
  }

  int query(int ind , int low , int high , int l , int r)
  {
    if((r<low) || (high<l))
    return INT_MAX;

    if((low>=l) && (high<=r))
    return seg[ind];

    int mid = (low+high)/2;
    int left = query(2*ind + 1 , low , mid , l ,r);
    int right = query(2*ind + 2 , mid+1 , high , l , r);
    return min(left,  right);
  }
};

int main()
{
  int n , q;
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
    int a , b;
    cin>>a>>b;
    int res = sg.query(0,0,n-1,a-1,b-1);
    cout<<res<<'\n';
  }
}