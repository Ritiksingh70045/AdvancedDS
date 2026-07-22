#include <bits/stdc++.h>
using namespace std;

const int LOGN = 20;
vector<vector<int>> adj, dp;
vector<int> lvl;

void dfs(int u, int p)
{
  dp[u][0] = p;
  for (int i = 1; i < LOGN; i++)
    dp[u][i] = dp[dp[u][i - 1]][i - 1];

  for (int v : adj[u])
  {
    if (v == p)
      continue;
    lvl[v] = lvl[u] + 1;
    dfs(v, u);
  }
}

int lca(int u, int v)
{
  if (lvl[u] < lvl[v])
    swap(u, v);

  int diff = lvl[u] - lvl[v];
  for (int i = 0; i < LOGN; i++)
    if (diff & (1 << i))
      u = dp[u][i];

  if (u == v)
    return u;

  for (int i = LOGN - 1; i >= 0; i--)
  {
    if (dp[u][i] != dp[v][i])
    {
      u = dp[u][i];
      v = dp[v][i];
    }
  }
  return dp[u][0];
}

int dist(int u, int v)
{
  int w = lca(u, v);
  return lvl[u] + lvl[v] - 2 * lvl[w];
}

int main()
{

  int n, q;
  cin >> n >> q;

  adj.resize(n + 1);
  dp.resize(n + 1, vector<int>(LOGN));
  lvl.resize(n + 1);

  for (int i = 0; i < n - 1; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  lvl[1] = 0;
  dfs(1, 0);

  while (q--)
  {
    int u, v;
    cin >> u >> v;
    cout << dist(u, v) << "\n";
  }
}
