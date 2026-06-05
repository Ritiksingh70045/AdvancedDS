#include <bits/stdc++.h>
using namespace std;

int main()
{
  string str1 = "abcde";
  string str2 = "bdgek";

  int n = str1.length();
  int m = str2.length();

  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (str1[i - 1] == str2[j - 1])
      {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  
  // Reconstructing the String
  int i = n;
  int j = m;
  string ans = "";

  while (i && j)
  {
    if (str1[i - 1] == str2[j - 1])
    {
      ans += str1[i - 1];
      i--;
      j--;
    }
    else if (dp[i - 1][j] < dp[i][j - 1])
    {
      j--;
    }
    else
      i--;
  }

  reverse(ans.begin(), ans.end());

  cout << ans;
}