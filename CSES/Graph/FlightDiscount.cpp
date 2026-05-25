#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> adj(n + 1);

  for (int i = 0; i < m; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;

    adj[u].push_back({v, w});
  }

  priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;

  vector<vector<long long>> dist(n + 1, vector<long long>(2, 1e18));
  pq.push({0, 1, 0});
  dist[1][0] = 0;

  while (!pq.empty())
  {
    long long cost = pq.top()[0];
    int node = pq.top()[1];
    int used = pq.top()[2];

    pq.pop();

    if (cost > dist[node][used])
      continue;

    for (auto it : adj[node])
    {
      int nbr = it.first;
      int wt = it.second;

      //Normal
      if (cost + wt < dist[nbr][used])
      {
        dist[nbr][used] = cost + wt;
        pq.push({dist[nbr][used], nbr, used});
      }

      //Coupon Used
      if (!used)
      {
        long long newCost = (cost + wt / 2);
        if (newCost < dist[nbr][1])
        {
          dist[nbr][1] = newCost;

          pq.push({dist[nbr][1], nbr, 1});
        }
      }
    }
  }
  cout<<dist[n][1];
}