#include <bits/stdc++.h>
using namespace std;
bool solve(int node, vector<int> &vis, vector<int> &pathVis, vector<vector<int>> &adj)
{
  vis[node] = 1;
  pathVis[node] = 1;

  for (auto nbr : adj[node])
  {
    if (!vis[nbr])
    {
      if (solve(nbr, vis, pathVis, adj))
        return true;
    }
    else if (pathVis[node])
      return true;
  }
  pathVis[node] = 0;
}
int main()
{
  int n = 5;

  vector<vector<int>> adj(n);

  adj[0].push_back(1);
  adj[1].push_back(2);
  adj[2].push_back(0);
  adj[2].push_back(3);
  adj[3].push_back(4);

  vector<int> vis(n, 0);
  vector<int> pathVis(n, 0);

  for (int i = 0; i < n; i++)
  {
    if (!vis[i])
    {
      bool ans = solve(i, vis, pathVis, adj);
      if (ans == true)
      {
        cout << "true";
        return 0;
      }
    }
  }
  cout << "false";
  return 0;
}