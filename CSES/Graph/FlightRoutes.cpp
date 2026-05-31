// This problem is NOT:
// enumerate all paths
// Instead:
// generate routes in increasing order of cost which is why modified Dijkstra works perfectly.

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<pair<int, int>>> adj(n + 1);
  for (int i = 0; i < m; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;

    adj[a].push_back({b, c});
  }

  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

  pq.push({0, 1});
  vector<long long> ans;
  vector<int> cnt(n + 1, 0); // To remove Infinite loop over same node more than k times because if a node gets popped from the queue k times then it would have been used in calculating k shortest path so no more popping.
  while (!pq.empty())
  {
    long long wt = pq.top().first;
    int node = pq.top().second;
    pq.pop();
    cnt[node]++;
    if (cnt[node] > k)
      continue;
    if (node == n)
      ans.push_back(wt);

    if (ans.size() == k)
      break;
    for (auto it : adj[node])
    {
      int nbr = it.first;
      int cost = it.second;

      pq.push({wt + cost, nbr});
    }
  }

  for (auto it : ans)
    cout << it << " ";
}