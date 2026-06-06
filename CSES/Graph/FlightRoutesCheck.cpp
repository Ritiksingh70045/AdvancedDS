#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj, radj;
vector<bool> vis;

void dfs(int node, vector<vector<int>> &graph)
{
  vis[node] = true;

  for (int nxt : graph[node])
  {
    if (!vis[nxt])
    {
      dfs(nxt, graph);
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  adj.resize(n + 1);
  radj.resize(n + 1);

  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;

    adj[a].push_back(b);
    radj[b].push_back(a);
  }

  vis.assign(n + 1, false);
  dfs(1, adj);

  for (int i = 1; i <= n; i++)
  {
    if (!vis[i])
    {
      cout << "NO\n";
      cout << 1 << " " << i << '\n';
      return 0;
    }
  }

  vis.assign(n + 1, false);
  dfs(1, radj);

  for (int i = 1; i <= n; i++)
  {
    if (!vis[i])
    {
      cout << "NO\n";
      cout << i << " " << 1 << '\n';
      return 0;
    }
  }

  cout << "YES\n";

  return 0;
}