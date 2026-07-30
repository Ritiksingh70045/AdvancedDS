#include <bits/stdc++.h>
using namespace std;
/*
int solve(int i, int j, string str1, string str2, vector<vector<int>> &dp)
{
  if (i >= str1.length() || j >= str2.length())
    return 0;

  if (dp[i][j] != -1)
    return dp[i][j];

  int ans = 0;
  if (str1[i] == str2[j])
  {
    ans = 1 + solve(i + 1, j + 1, str1, str2, dp);
  }
  else
  {
    ans = max(ans, max(solve(i + 1, j, str1, str2, dp), solve(i, j + 1, str1, str2, dp)));
  }

  return dp[i][j] = ans;
}

*/
int main()
{
  string str1 = "abcde";
  string str2 = "abced";
  int m = str1.length();
  int n = str2.length();
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      int ans = 0;
      if (str1[i - 1] == str2[j - 1])
      {
        ans = 1 + dp[i - 1][j - 1];
      }
      else
      {
        ans = max(dp[i - 1][j], dp[i][j - 1]);
      }

      dp[i][j] = ans;
    }
  }
  int i = m;
  int j = n;
  string str = "";
  while(i && j)
  {
    if(str1[i-1] == str2[j-1])
    {
      str += str1[i-1];
      i--;
      j--;
    }
    else
    {
      if(dp[i][j-1] >= dp[i-1][j])
      {
        j--;
      }
      else
      {
        i--;
      }
    }
  }

  reverse(str.begin() , str.end());
  cout<<str;
}