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

  vector<long long> dist(n + 1, 1e18);

  priority_queue<pair<long long, int> , vector<pair<long long,int>> , greater<pair<long long , int>>> pq;

  pq.push({0, 1});
  dist[1] = 0;
  while (!pq.empty())
  {
    long long wt = pq.top().first;
    int node = pq.top().second;
    pq.pop();
    if(wt > dist[node])  // Important for the Stale Data
    continue;
    for (auto it : adj[node])
    {
      int nbrNode = it.first;
      int nbrWt = it.second;

      if (wt + nbrWt < dist[nbrNode])
      {
        dist[nbrNode] = wt + nbrWt;
        pq.push({dist[nbrNode], nbrNode});
      }
    }
  }

  for (int i = 1; i <= n; i++)
  {
    cout << dist[i] << " ";
  }
}