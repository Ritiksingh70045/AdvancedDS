#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int LOGN = 18;

vector<int> adj[MAXN];
int level[MAXN];
int dp[MAXN][LOGN];

void dfs(int u, int parent)
{
  level[u] = level[parent] + 1;
  dp[u][0] = parent;

  // Store 2^i-th ancestor
  for (int i = 1; i < LOGN; i++)
  {
    dp[u][i] = dp[dp[u][i - 1]][i - 1];
  }

  for (int v : adj[u])
  {
    if (v == parent)
      continue;

    dfs(v, u);
  }
}

int lca(int u, int v)
{

  // Make u the deeper node
  if (level[u] < level[v])
    swap(u, v);

  // Bring u to the same level as v
  int diff = level[u] - level[v];

  for (int i = 0; i < LOGN; i++)
  {
    if ((diff >> i) & 1)
    {
      u = dp[u][i];
    }
  }

  // If both are same, this is the LCA
  if (u == v)
    return u;

  // Move both nodes upward
  for (int i = LOGN - 1; i >= 0; i--)
  {
    if (dp[u][i] != dp[v][i])
    {
      u = dp[u][i];
      v = dp[v][i];
    }
  }

  // Their immediate parent is the LCA
  return dp[u][0];
}

int main()
{
  int n, q;
  cin >> n >> q;

  // Build the tree
  for (int i = 0; i < n - 1; i++)
  {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // Root is node 1
  level[0] = -1;
  dfs(1, 0);

  // Answer queries
  while (q--)
  {
    int u, v;
    cin >> u >> v;

    cout << lca(u, v) << '\n';
  }

  return 0;
}