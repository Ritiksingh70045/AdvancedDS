#include<bits/stdc++.h>
using namespace std;

int solve(int row , int prevcol , vector<vector<int>>& dp , vector<vector<int>>& mat)
{
  if(row >= mat.size())
  return 0;

  if(dp[row][prevcol] != -1)
  return dp[row][prevcol];
  int ans = 0;
  for(int col = 1;col<=mat[0].size();col++)
  {
    if(col == prevcol)
    continue;
    ans = max(ans , mat[row][col-1] + solve(row+1 , col , dp , mat));
  }
  dp[row][prevcol] = ans;
}
// int main()
// {
//   int m,n;
//   cin>>m>>n;
//   vector<vector<int>> mat(m,vector<int>(n,0));

//   for(int i=0;i<m;i++)
//   {
//     for(int j=0;j<n;j++)
//     {
//       cin>>mat[i][j];
//     }
//   }

//   vector<vector<int>> dp(m,vector<int>(n+1,-1));
//   cout << solve(0,0,dp,mat);
// }

int main()
{
  int m,n;
  cin>>m>>n;
  vector<vector<int>> mat(m,vector<int>(n,0));

  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
      cin>>mat[i][j];
    }
  }

  vector<vector<int>> dp(m+1,vector<int>(n+1,0));
  for(int row=m-1;row>=0;row--)
  {
    for(int prevcol=0;prevcol<=n;prevcol++)
    {
      int ans = 0;
      for(int col=1;col<=n;col++)
      {
        if(col == prevcol)
        continue;
        ans = max(ans , mat[row][col-1] + dp[row+1][col]);
      }
      dp[row][prevcol] = ans;
    }
  }
  cout << dp[0][0];
}