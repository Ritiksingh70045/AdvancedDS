#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;

  vector<vector<long long>> edges;

  for (int i = 0; i < m; i++)
  {
    long long u, v, w;
    cin >> u >> v >> w;

    edges.push_back({u, v, w});
  }

  vector<long long> dist(n + 1, 0);

  vector<int> parent(n + 1, -1);

  int x = -1;

  // BELLMAN FORD

  for (int i = 1; i <= n; i++)
  {
    x = -1;

    for (auto e : edges)
    {
      int u = e[0];
      int v = e[1];
      long long w = e[2];

      if (dist[u] + w < dist[v])
      {
        dist[v] = dist[u] + w;

        parent[v] = u;

        x = v;
      }
    }
  }

  // NO NEGATIVE CYCLE

  if (x == -1)
  {
    cout << "NO";
    return 0;
  }

  // MOVE INSIDE CYCLE

  for (int i = 0; i < n; i++)
  {
    x = parent[x];
  }

  // RECONSTRUCT CYCLE

  vector<int> cycle;

  int cur = x;

  do
  {
    cycle.push_back(cur);

    cur = parent[cur];

  } while (cur != x);

  cycle.push_back(x);

  reverse(cycle.begin(), cycle.end());

  cout << "YES\n";

  for (auto node : cycle)
  {
    cout << node << " ";
  }

  return 0;
}