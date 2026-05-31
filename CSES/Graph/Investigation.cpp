#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
const int MOD = 1e9 + 7;

int main()
{
  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> adj(n + 1);

  for (int i = 0; i < m; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;

    adj[a].push_back({b, c});
  }

  vector<long long> dist(n + 1, INF);
  vector<long long> ways(n + 1, 0);

  vector<int> mnFlight(n + 1, 1e9);
  vector<int> mxFlight(n + 1, 0);

  priority_queue<
      pair<long long, int>,
      vector<pair<long long, int>>,
      greater<pair<long long, int>>>
      pq;

  dist[1] = 0;
  ways[1] = 1;
  mnFlight[1] = 0;
  mxFlight[1] = 0;

  pq.push({0, 1});

  while (!pq.empty())
  {
    long long d = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if (d > dist[node])
      continue;

    for (auto it : adj[node])
    {
      int nbr = it.first;
      int wt = it.second;

      long long newDist = dist[node] + wt;

      // Better shortest path found
      if (newDist < dist[nbr])
      {
        dist[nbr] = newDist;

        ways[nbr] = ways[node];

        mnFlight[nbr] = mnFlight[node] + 1;
        mxFlight[nbr] = mxFlight[node] + 1;

        pq.push({dist[nbr], nbr});
      }

      // Another shortest path found
      else if (newDist == dist[nbr])
      {
        ways[nbr] =
            (ways[nbr] + ways[node]) % MOD;

        mnFlight[nbr] =
            min(mnFlight[nbr],
                mnFlight[node] + 1);

        mxFlight[nbr] =
            max(mxFlight[nbr],
                mxFlight[node] + 1);
      }
    }
  }

  cout << dist[n] << " "
       << ways[n] << " "
       << mnFlight[n] << " "
       << mxFlight[n];

  return 0;
}