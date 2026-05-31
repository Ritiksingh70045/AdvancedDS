#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

int solve(int node , vector<vector<int>>& adj , vector<int>& dp)
{
  if(node == dp.size()-1)
  return 1;

  if(dp[node] != -1)
  return dp[node];
  int ans = 0;
  for(int nbr : adj[node])
  {
    ans = (ans + (solve(nbr,adj,dp))%mod)%mod;
  }

  return dp[node] = ans;
}
int main()
{
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n + 1);
  vector<int> dp(n+1,-1);
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;

    adj[a].push_back(b);
  }

  solve(1,adj,dp);
  cout << dp[1];
}