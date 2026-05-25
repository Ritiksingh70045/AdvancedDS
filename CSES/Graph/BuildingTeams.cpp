#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> color(n + 1,0);
  vector<int> vis(n + 1);

  for (int i = 1; i <= n; i++)
  {
    if (vis[i])
      continue;

    queue<pair<int, int>> q;
    q.push({i, 1});
    vis[i] = 1;
    color[i] = 1;
    while (!q.empty())
    {
      int node = q.front().first;
      int clr = q.front().second;
      q.pop();
      for (auto nbr : adj[node])
      {
        if (vis[nbr])
        {
          if (color[nbr] == clr)
          {
            cout << "IMPOSSIBLE";
            return 0;
          }
          continue;
        }

        vis[nbr] = 1;
        color[nbr] = (clr == 1) ? 2 : 1;
        q.push({nbr, color[nbr]});
      }
    }
  }

  for (int i = 1; i <= n; i++)
  {
    cout << color[i] << " ";
  }
}