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

  vector<int> parent(n + 1);

  queue<int> q;
  q.push(1);
  vector<int> vis(n + 1, 0);
  vis[1] = 1;
  while (!q.empty())
  {
    int node = q.front();
    q.pop();

    for (int nbr : adj[node])
    {
      if (vis[nbr])
        continue;
      vis[nbr] = 1;
      parent[nbr] = node;
      q.push(nbr);
    }
  }
  if (!vis[n])
  {
    cout << "IMPOSSIBLE";
    return 0;
  }
  vector<int> ans;
  int curr = n;
  ans.push_back(n);
  while (curr != 1)
  {
    ans.push_back(parent[curr]);
    curr = parent[curr];
  }
  reverse(ans.begin(), ans.end());

  cout << ans.size() << '\n';
  for (auto it : ans)
    cout << it << " ";
}