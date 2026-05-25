#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m, q;
  cin >> n >> m >> q;

  vector<vector<long long>> mat(
      n + 1,
      vector<long long>(n + 1, 1e18));

  // DISTANCE FROM NODE TO ITSELF = 0

  for (int i = 1; i <= n; i++)
  {
    mat[i][i] = 0;
  }

  // UNDIRECTED GRAPH

  for (int i = 0; i < m; i++)
  {
    int a, b, w;
    cin >> a >> b >> w;

    mat[a][b] = min(mat[a][b], 1LL * w);
    mat[b][a] = min(mat[b][a], 1LL * w);
  }

  // STORE QUERIES

  vector<pair<int, int>> queries;

  for (int i = 0; i < q; i++)
  {
    int u, v;
    cin >> u >> v;

    queries.push_back({u, v});
  }

  // FLOYD WARSHALL

  for (int k = 1; k <= n; k++)
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if (mat[i][k] == 1e18 ||
            mat[k][j] == 1e18)
          continue;

        mat[i][j] = min(
            mat[i][j],
            mat[i][k] + mat[k][j]);
      }
    }
  }

  // ANSWER QUERIES

  for (auto it : queries)
  {
    int u = it.first;
    int v = it.second;

    if (mat[u][v] == 1e18)
      cout << -1 << '\n';
    else
      cout << mat[u][v] << '\n';
  }

  return 0;
}




// ---------- Python Version ----------//




// import math

// n, m = map(int, input().split())

// INF = float('inf')

// # DISTANCE MATRIX

// dist = [[INF] * (n + 1) for _ in range(n + 1)]

// # DISTANCE FROM NODE TO ITSELF = 0

// for i in range(1, n + 1):
//     dist[i][i] = 0

// # INPUT GRAPH

// for _ in range(m):
//     u, v, w = map(int, input().split())

//     # DIRECTED GRAPH

//     dist[u][v] = min(dist[u][v], w)

//     # FOR UNDIRECTED GRAPH:
//     # dist[v][u] = min(dist[v][u], w)

// # ================= FLOYD WARSHALL =================

// for k in range(1, n + 1):
//     for i in range(1, n + 1):
//         for j in range(1, n + 1):

//             if dist[i][k] == INF or dist[k][j] == INF:
//                 continue

//             dist[i][j] = min(
//                 dist[i][j],
//                 dist[i][k] + dist[k][j]
//             )

// # ================= NEGATIVE CYCLE DETECTION =================

// negative_cycle = False

// for i in range(1, n + 1):
//     if dist[i][i] < 0:
//         negative_cycle = True
//         break

// if negative_cycle:
//     print("Negative Cycle Detected")
// else:
//     print("No Negative Cycle")

// # ================= SHORTEST DISTANCE QUERY =================

// source, destination = map(int, input().split())

// if dist[source][destination] == INF:
//     print("No Path Exists")
// else:
//     print("Shortest Distance =", dist[source][destination])