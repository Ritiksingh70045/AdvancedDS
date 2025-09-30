#include <bits/stdc++.h>
using namespace std;

void dfs_binary_lifting(int node, int parent, vector<vector<int>> &adj, vector<vector<int>> &dp, vector<int> &lvl)
{
  if (parent == -1)
  {
    lvl[node] = 0;
  }
  else
  {
    lvl[node] = lvl[parent] + 1;
  }
  dp[node][0] = parent;
  for (int i = 1; i < 18; i++)
  {
    if (dp[node][i - 1] != -1)
    {
      dp[node][i] = dp[dp[node][i - 1]][i - 1];
    }
    else
    {
      dp[node][i] = -1;
    }
  }
  for (auto it : adj[node])
  {
    if (it != parent)
    {
      dfs_binary_lifting(it, node, adj, dp, lvl);
    }
  }
}
int lca(int u, int v, vector<int> &lvl, vector<vector<int>> &dp)
{
  if (lvl[u] < lvl[v])
  {
    swap(u, v);
  }

  int diff = lvl[u] - lvl[v];
  for (int i = 0; i < 18; i++)
  {
    if ((1 << i) & diff)
    {
      u = dp[u][i];
    }
  }

  if (u == v)
  {
    return u;
  }
  for (int i = 17; i >= 0; i--)
  {
    if ((dp[u][i] != -1) && (dp[u][i] != dp[v][i]))
    {
      u = dp[u][i];
      v = dp[v][i];
    }
  }
  return dp[u][0];
}

bool checkPythagoreas(int a, int b, int c)
{
  if (a > b && a > c)
  {
    return (a * a == b * b + c * c);
  }
  else if (b > a && b > c)
  {
    return (b * b == a * a + c * c);
  }
  else
  {
    return (c * c == a * a + b * b);
  }
}
int main()
{
  int n = 20;
  vector<int> treeFrom = {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9};
  vector<int> treeTo =   {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
  int x = 5, y = 6, z = 7;

  vector<vector<int>> adj(n);
  for (int i = 0; i < treeFrom.size(); i++)
  {
    adj[treeFrom[i]].push_back(treeTo[i]);
    adj[treeTo[i]].push_back(treeFrom[i]);
  }

  vector<int> lvl(n, 0);
  vector<vector<int>> dp(n, vector<int>(18, -1));
  dfs_binary_lifting(0, -1, adj, dp, lvl);

  int count = 0;
  for (int node = 0; node < n; node++)
  {
    int dist1 = lvl[x] + lvl[node] - 2 * lvl[lca(x, node, lvl, dp)];
    int dist2 = lvl[y] + lvl[node] - 2 * lvl[lca(y, node, lvl, dp)];
    int dist3 = lvl[z] + lvl[node] - 2 * lvl[lca(z, node, lvl, dp)];

    if (dist1 == 0 || dist2 == 0 || dist3 == 0)
      continue;
    if (checkPythagoreas(dist1, dist2, dist3))
    {
      count++;
    }
  }
  cout << "Count of Pythagorean triples: " << count << endl;
  return 0;
}
