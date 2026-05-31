#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int i, int j, vector<vector<int>> &dp)
{
  if (i == j)
    return 0;

  if (dp[i][j] != -1)
    return dp[i][j];

  int minCost = 1e9;
  for (int k = i; k < j; k++)
  {
    int cost1 = solve(arr, i, k, dp);
    int cost2 = solve(arr, k + 1, j, dp);
    int costTomultiply = arr[i - 1] * arr[k] * arr[j];

    minCost = min(minCost, cost1 + cost2 + costTomultiply);
  }
  return dp[i][j] = minCost;
}

int main()
{
  vector<int> arr = {40, 20, 30, 10, 30};
  int n = arr.size();
  vector<vector<int>> dp(n, vector<int>(n, -1));

  int ans = solve(arr, 1, n - 1, dp);
  cout << ans << '\n';
}