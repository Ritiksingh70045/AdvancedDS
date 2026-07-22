// #include <bits/stdc++.h>
// using namespace std;

// vector<vector<int>> dp;

// int solve(int ind, int sum, vector<int> &nums, int target)
// {
//   if (ind == nums.size())
//     return (sum == target);

//   if (sum > target) // works only if all numbers are positive
//     return 0;

//   if (dp[ind][sum] != -1)
//     return dp[ind][sum];

//   int notTake = solve(ind + 1, sum, nums, target);

//   int take = solve(ind + 1, sum + nums[ind], nums, target);

//   return dp[ind][sum] = notTake + take;
// }

// int main()
// {
//   vector<int> nums = {4, 9, 5, 5, 1};
//   int target = 10;

//   int n = nums.size();

//   dp.assign(n + 1, vector<int>(target + 1, -1));

//   cout << solve(0, 0, nums, target);
// }



// Tabulation Method
#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> nums = {4, 9, 5, 5, 1};
  int target = 10;

  int n = nums.size();

  vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

  // Base case
  dp[n][target] = 1;

  for (int ind = n - 1; ind >= 0; ind--)
  {
    for (int sum = target; sum >= 0; sum--)
    {
      int notTake = dp[ind + 1][sum];

      int take = 0;
      if (sum + nums[ind] <= target)
        take = dp[ind + 1][sum + nums[ind]];

      dp[ind][sum] = notTake + take;
    }
  }

  cout << dp[0][0];
}