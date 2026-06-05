#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int solve(int i, int j, string &s1, string &s2,
            vector<vector<int>> &dp)
  {

    if (i == s1.size() || j == s2.size())
      return 0;

    if (dp[i][j] != -1)
      return dp[i][j];

    if (s1[i] == s2[j])
    {
      return dp[i][j] =
                 1 + solve(i + 1, j + 1, s1, s2, dp);
    }

    return dp[i][j] =
               max(solve(i + 1, j, s1, s2, dp),
                   solve(i, j + 1, s1, s2, dp));
  }

  int longestCommonSubsequence(string text1, string text2)
  {

    int n = text1.size();
    int m = text2.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    return solve(0, 0, text1, text2, dp);
  }
};

int main()
{
  Solution sol;
  int ans = sol.longestCommonSubsequence("abcdfwxy" , "dewxy");
  cout<<ans;
}