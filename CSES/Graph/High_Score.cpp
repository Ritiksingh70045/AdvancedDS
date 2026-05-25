#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;

  vector<vector<long long>> edges;

  vector<vector<int>> adj(n + 1);

  for (int i = 0; i < m; i++)
  {
    int u, v;
    long long w;

    cin >> u >> v >> w;

    // STORE NEGATIVE WEIGHT
    // MAX SCORE -> MIN DISTANCE

    edges.push_back({u, v, -w});

    adj[u].push_back(v);
  }

  vector<long long> dist(n + 1, 1e18);

  dist[1] = 0;

  // ================= BELLMAN FORD =================

  for (int i = 1; i <= n - 1; i++)
  {
    for (auto it : edges)
    {
      int u = it[0];
      int v = it[1];
      long long w = it[2];

      if (dist[u] == 1e18)
        continue;

      if (dist[u] + w < dist[v])
      {
        dist[v] = dist[u] + w;
      }
    }
  }

  // ================= DETECT NEGATIVE CYCLE =================

  vector<int> affected;

  for (auto it : edges)
  {
    int u = it[0];
    int v = it[1];
    long long w = it[2];

    if (dist[u] == 1e18)
      continue;

    if (dist[u] + w < dist[v])
    {
      affected.push_back(v);
    }
  }

  // ================= BFS TO CHECK REACHABILITY TO N =================

  vector<int> vis(n + 1, 0);

  queue<int> q;

  for (auto node : affected)
  {
    q.push(node);
    vis[node] = 1;
  }

  while (!q.empty())
  {
    int node = q.front();
    q.pop();

    if (node == n)
    {
      cout << -1;
      return 0;
    }

    for (auto nbr : adj[node])
    {
      if (!vis[nbr])
      {
        vis[nbr] = 1;
        q.push(nbr);
      }
    }
  }

  cout << -dist[n];

  return 0;
}