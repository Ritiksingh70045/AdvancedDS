#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &dist, vector<int> &next, vector<int> &vis, vector<vector<int>> &adj)
{
  vis[node] = 1;
  for (int nbr : adj[node])
  {
    if (!vis[nbr])
      dfs(nbr, dist, next, vis, adj);

    if ((dist[nbr] != -1) && (dist[nbr] + 1 > dist[node]))
    {
      dist[node] = dist[nbr] + 1;
      next[node] = nbr;
    }
  }
}
int main()
{
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;

    adj[a].push_back(b);
  }

  vector<int> dist(n + 1, -1);
  vector<int> next(n + 1, 0);
  vector<int> vis(n + 1, 0);
  dist[n] = 1;

  dfs(1, dist, next,vis, adj);

  if (dist[1] == -1)
  {
    cout << "IMPOSSIBLE";
  }
  else
  {
    vector<int> res;
    int node = 1;

    while (node)
    {
      res.push_back(node);
      node = next[node];
    }
    cout << res.size() << '\n';
    for (auto it : res)
      cout << it << " ";
  }
}