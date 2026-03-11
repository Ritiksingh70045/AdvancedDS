#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool solve(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
  {
    if (target == 0)
      return true;

    if (ind == 0)
      return arr[0] == target;

    if (dp[ind][target] != -1)
      return dp[ind][target];

    bool notTaken = solve(ind - 1, target, arr, dp);

    bool taken = false;
    if (arr[ind] <= target)
    {
      taken = solve(ind - 1, target - arr[ind], arr, dp);
    }

    return dp[ind][target] = notTaken || taken;
  }

  bool subsetSumToK(int n, int k, vector<int> &arr)
  {
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return solve(n - 1, k, arr, dp);
  }
};

int main()
{
  vector<int> arr = {1,2,5};
  int k = 4;
  int n = arr.size();

  Solution sol;
  if (sol.subsetSumToK(n, k, arr))
    cout << "Subset with the given target found";
  else
    cout << "Subset with the given target not found";

  return 0;
}

// while doing it in tabular method one important base case and that is if(arr[0] <= target) then {dp[0][arr[0]] = true};