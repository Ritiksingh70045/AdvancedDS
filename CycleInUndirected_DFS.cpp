#include <bits/stdc++.h>
using namespace std;

bool detectCycle(int node, int parent,
                 vector<vector<int>> &adj,
                 vector<bool> &vis)
{
  vis[node] = true;

  for (auto it : adj[node])
  {
    if (!vis[it])
    {
      if (detectCycle(it, node, adj, vis))
        return true;
    }
    else if (it != parent)
    {
      return true;
    }
  }

  return false;
}

int main()
{
  vector<vector<int>> adj = {
      {1, 4},
      {0, 2, 5},
      {1, 3},
      {2},
      {0, 5},
      {1, 4}};

  int n = adj.size();
  vector<bool> vis(n, false);

  for (int i = 0; i < n; i++)
  {
    if (!vis[i])
    {
      if (detectCycle(i, -1, adj, vis))
      {
        cout << "true";
        return 0;
      }
    }
  }

  cout << "false";
}