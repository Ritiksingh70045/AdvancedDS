#include <bits/stdc++.h>
using namespace std;

bool detectCycle(int start, vector<vector<int>> &adj, vector<bool> &vis)
{
  queue<pair<int, int>> q;
  q.push({start, -1});
  vis[start] = true;

  while (!q.empty())
  {
    int node = q.front().first;
    int parent = q.front().second;
    q.pop();

    for (auto it : adj[node])
    {
      if (!vis[it])
      {
        vis[it] = true;
        q.push({it, node});
      }
      else if (it != parent)
      {
        return true;
      }
    }
  }
  return false;
}

int main()
{
  vector<vector<int>> adj = {{1, 4}, {0, 2, 5}, {1, 3}, {2}, {0, 5}, {1, 4}};
  int n = adj.size();
  vector<bool> vis(n, false);

  for (int i = 0; i < n; i++)
  {
    if (!vis[i])
    {
      if (detectCycle(i, adj, vis))
      {
        cout << "true";
        return 0;
      }
    }
  }

  cout << "false";
}