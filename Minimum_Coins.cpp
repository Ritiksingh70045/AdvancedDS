#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int coinChange(vector<int> &coins, int amount)
  {
    vector<int> dp(amount + 1, -2);

    return helper(coins, amount, dp);
  }

private:
  int helper(vector<int> &coins, int rem, vector<int> &dp)
  {
    if (rem == 0)
      return 0;

    if (rem < 0)
      return -1;

    if (dp[rem] != -2)
      return dp[rem];

    int mini = INT_MAX;

    for (int coin : coins)
    {
      int res = helper(coins, rem - coin, dp);

      if (res >= 0 && res < mini)
        mini = 1 + res;
    }

    dp[rem] = (mini == INT_MAX) ? -1 : mini;
    return dp[rem];
  }
};

int main()
{
  vector<int> coins = {1, 2, 5};
  int amount = 11;

  Solution obj;
  cout << obj.coinChange(coins, amount) << endl;
  return 0;
}
