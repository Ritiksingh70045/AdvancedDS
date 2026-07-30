#include <bits/stdc++.h>
using namespace std;

int solve(int ind, int w, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp)
{
  if (w == 0)
    return 0;

  if (ind < 0)
    return -1e9;

  if (dp[ind][w] != -1)
    return dp[ind][w];

  int notTake = solve(ind - 1, w, wt, val, dp);
  int take = 0;
  if (wt[ind] <= w)
  {
    take = val[ind] + solve(ind, w - wt[ind], wt, val, dp);
  }

  return dp[ind][w] = max(take, notTake);
}
int main()
{
  int n = 3;
  int w = 8;
  vector<int> wt = {2, 4, 6};
  vector<int> val = {5, 11, 20};

  vector<vector<int>> dp(n, vector<int>(w + 1, -1));
  cout << solve(n - 1, w, wt, val, dp);
}