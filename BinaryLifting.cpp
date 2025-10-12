#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int LOGN = 17;

vector<int> adj[MAXN];
int lvl[MAXN];
int dp[MAXN][LOGN];

void dfs(int u, int p)
{
  lvl[u] = lvl[p] + 1;
  dp[u][0] = p;
  for (int i = 1; i < LOGN; i++)
    dp[u][i] = dp[dp[u][i - 1]][i - 1];

  for (auto v : adj[u])
  {
    if (v == p)
      continue;
    dfs(v, u);
  }
}

int lca(int u, int v)
{
  if (lvl[u] < lvl[v])
    swap(u, v);

  int diff = lvl[u] - lvl[v];
  for (int i = 0; i < LOGN; i++)
    if ((diff >> i) & 1)
      u = dp[u][i];

  if (u == v)
    return u;

  for (int i = LOGN - 1; i >= 0; i--)
    if (dp[u][i] != dp[v][i])
    {
      u = dp[u][i];
      v = dp[v][i];
    }

  return dp[u][0];
}

int main()
{
  int n, q;
  cin >> n >> q;

  for (int i = 1; i <= n - 1; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  lvl[0] = -1;
  dfs(1, 0);

  while (q--)
  {
    int u, v;
    cin >> u >> v;
    cout << lca(u, v) << "\n";
  }

  return 0;
}
