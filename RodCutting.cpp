#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int solve(int ind, int len, vector<int> &price, vector<vector<int>> &dp)
  {
    if (ind == 0)
      return len * price[0];

    if (dp[ind][len] != -1)
      return dp[ind][len];

    int notTake = solve(ind - 1, len, price, dp);

    int take = INT_MIN;
    int rodLength = ind + 1;

    if (rodLength <= len)
      take = price[ind] + solve(ind, len - rodLength, price, dp);

    return dp[ind][len] = max(take, notTake);
  }

  int rodCutting(vector<int> &price, int n)
  {

    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    return solve(n - 1, n, price, dp);
  }
};

int main()
{

  int n = 8;
  vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};

  Solution obj;

  cout << "The maximum obtainable value is: "
       << obj.rodCutting(price, n) << endl;

  return 0;
}