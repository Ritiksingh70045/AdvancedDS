#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;

  const long long INF = 1e18;

  // DISTANCE MATRIX

  vector<vector<long long>> dist(
      n + 1,
      vector<long long>(n + 1, INF));

  // DISTANCE FROM NODE TO ITSELF = 0

  for (int i = 1; i <= n; i++)
  {
    dist[i][i] = 0;
  }

  // INPUT GRAPH

  for (int i = 0; i < m; i++)
  {
    int u, v;
    long long w;

    cin >> u >> v >> w;

    // DIRECTED GRAPH

    dist[u][v] = min(dist[u][v], w);

    // FOR UNDIRECTED GRAPH ALSO ADD:
    // dist[v][u] = min(dist[v][u], w);
  }

  // ================= FLOYD WARSHALL =================

  for (int k = 1; k <= n; k++)
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        // PATH DOES NOT EXIST

        if (dist[i][k] == INF ||
            dist[k][j] == INF)
          continue;

        dist[i][j] = min(
            dist[i][j],
            dist[i][k] + dist[k][j]);
      }
    }
  }

  // ================= NEGATIVE CYCLE DETECTION =================

  bool negativeCycle = false;

  for (int i = 1; i <= n; i++)
  {
    // NEGATIVE CYCLE EXISTS

    if (dist[i][i] < 0)
    {
      negativeCycle = true;
      break;
    }
  }

  if (negativeCycle)
  {
    cout << "Negative Cycle Detected\n";
  }
  else
  {
    cout << "No Negative Cycle\n";
  }

  // ================= PRINT SHORTEST DISTANCES =================

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (dist[i][j] == INF)
        cout << "INF ";
      else
        cout << dist[i][j] << " ";
    }

    cout << '\n';
  }

  return 0;
}