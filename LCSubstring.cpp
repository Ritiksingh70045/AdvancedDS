#include <bits/stdc++.h>
using namespace std;

int main()
{
  string str1 = "non";
  string str2 = "afnksndobced";
  int m = str1.length();
  int n = str2.length();

  vector<vector<int>> dp(m+1 , vector<int>(n+1 , 0));
  int ans = 0;
  for(int i=1;i<=m;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(str1[i-1] == str2[j-1])
      {
        dp[i][j] = 1 + dp[i-1][j-1];
        ans = max(ans , dp[i][j]);
      }
      else
      {
        dp[i][j] = 0;
      }
    }
  }

  cout<<ans;
}