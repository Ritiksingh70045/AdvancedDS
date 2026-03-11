#include <bits/stdc++.h>
using namespace std;
int solve(int ind ,int n, vector<int>& dp , vector<int>& nums)
{
  if(ind >= n)
  return 0;
  if(dp[ind] != -1)
  return dp[ind];

  int take = nums[ind] + solve(ind+2 , n , dp , nums);
  int notTake = solve(ind+1 , n , dp , nums);

  return dp[ind] = max(take , notTake);
}
int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
    // vector<int> dp(n+2,0);
    int curr = 0;
    int next1 = 0;
    int next2 = 0;
  // solve(0,n,dp,nums);
  for(int i=n-1;i>=0;i--)
  {
    int take = nums[i] + next2;
    int notTake = next1;

    curr = max(take , notTake);
    next2 = next1;
    next1 = curr;
  }

  cout << curr;
}