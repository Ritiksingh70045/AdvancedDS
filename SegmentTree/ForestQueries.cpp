#include<bits/stdc++.h>
using namespace std;

int solve(int a,int b,int c,int d,vector<vector<int>>& parr)
{
  return parr[c][d]-parr[a-1][d] - parr[c][b-1] + parr[a-1][b-1];
}

int main()
{
  int n,q;
  cin>>n>>q;
  vector<vector<char>> v(n+1,vector<char>(n+1,0));
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      cin>>v[i][j];
    }
  }
  vector<vector<int>> parr(n+1,vector<int>(n+1,0));
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(v[i][j] == '.')
      parr[i][j] = 0;
      else
      parr[i][j] = 1;
    }
  }

  for(int i=1;i<=n;i++)
  {
    for(int j=2;j<=n;j++)
    {
      parr[i][j] = parr[i][j-1] + parr[i][j];
    }
  }

  for(int j=1;j<=n;j++)
  {
    for(int i=2;i<=n;i++)
    {
      parr[i][j] = parr[i-1][j] + parr[i][j];
    }
  }

  while(q--)
  {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int ans = solve(a,b,c,d,parr);
    cout<<ans<<'\n';
  }
}