#include<bits/stdc++.h>
using namespace std;

class Solution{
  public : 
  int solve(int ind , int target , vector<int>& nums , vector<vector<int>>& dp)
  {
    if(target == 0)
    return 1;
    if(ind >= nums.size())
    return 0;

    if(dp[ind][target] != -1)
    return dp[ind][target];

    int notTake = solve(ind+1 , target , nums , dp);
    int take = 0;
    if(nums[ind] <= target)
    {
      take = solve(ind+1 , target-nums[ind] , nums , dp);
    }
    return dp[ind][target] = (take + notTake);
  }
};

int main()
{
  Solution sol;
  int n;
  cin>>n;
  vector<int> nums(n);
  for(int i=0;i<n;i++)
  cin>>nums[i];

  int k;
  cin>>k;

  vector<vector<int>> dp(n , vector<int>(k+1 , -1));
  cout << sol.solve(0,k,nums,dp);
}