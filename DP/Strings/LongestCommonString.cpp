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
      return dp[i][j] = 1 + solve(i + 1, j + 1, s1, s2, dp);

    return dp[i][j] = 0;
  }

  int longestCommonSubstring(string s1, string s2)
  {

    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        ans = max(ans, solve(i, j, s1, s2, dp));
      }
    }

    return ans;
  }
};

int main()
{
  string s1, s2;
  cin >> s1 >> s2;

  Solution obj;
  cout << obj.longestCommonSubstring(s1, s2);
}