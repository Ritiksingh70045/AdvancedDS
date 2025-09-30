#include<bits/stdc++.h>
using namespace std;

class SGTree
{
  vector<long long> seg;

  public  : 
  SGTree(int n)
  {
    seg.resize(4*n+1);
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
  }

  long long query(int ind , int low , int high , int l , int r)
  {
    if((r<low) || (high<l))
    return 0;

    if((low>=l) && (high <= r))
    return seg[ind];

    int mid = (low+high)/2;
    long long left = query(2*ind + 1 , low , mid , l , r);
    long long right = query(2*ind + 2 , mid + 1 , high , l , r);
    return (left+right);
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
    long long res = sg.query(0,0,n-1,a-1,b-1);
    cout<<res<<'\n';
  }
}