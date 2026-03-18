#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<pair<int, int>>> &adj, int src)
{
  vector<int> dist(V, 1e9);

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  dist[src] = 0;
  pq.push({0, src});

  while (!pq.empty())
  {
    int d = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    for (auto nbr : adj[node])
    {
      int next = nbr.first;
      int wt = nbr.second;

      if (dist[node] + wt < dist[next])
      {
        dist[next] = dist[node] + wt;
        pq.push({dist[next], next});
      }
    }
  }

  return dist;
}