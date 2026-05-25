#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> parent, vis;
int startNode, endNode;

bool dfs(int node, int par)
{
  vis[node] = 1;

  for (auto nbr : adj[node])
  {
    if (nbr == par)
      continue;

    if (vis[nbr])
    {
      startNode = nbr;
      endNode = node;
      return true;
    }

    parent[nbr] = node;

    if (dfs(nbr, node))
      return true;
  }

  return false;
}

int main()
{
  int n, m;
  cin >> n >> m;
  adj.resize(n + 1);
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  parent.resize(n + 1, -1);
  vis.resize(n + 1, 0);

  bool flag = false;
  for (int i = 1; i <= n; i++)
  {
    if (!vis[i])
    {
      if (dfs(i, parent[i]))
      {
        flag = true;
        break;
      }
    }
  }
  if (!flag)
  {
    cout << "IMPOSSIBLE";
    return 0;
  }

  vector<int> ans;
  ans.push_back(startNode);
  int node = endNode;

  while (node != startNode)
  {
    ans.push_back(node);
    node = parent[node];
  }
  ans.push_back(startNode);

  reverse(ans.begin() , ans.end());

  cout<<ans.size()<<'\n';
  for(auto it : ans)
  cout<<it<<" ";
}