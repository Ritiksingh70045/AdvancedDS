#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n = 9;
  int m = 10;

  vector<vector<int>> adj(n);

  vector<pair<int, int>> edges = {
      {0, 1},
      {0, 3},
      {3, 4},
      {4, 5},
      {5, 6},
      {1, 2},
      {2, 6},
      {6, 7},
      {7, 8},
      {6, 8}};

  // Undirected Graph
  for (auto edge : edges)
  {
    int u = edge.first;
    int v = edge.second;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int src = 0;
  int step = 1;
  queue<int> q;
  vector<int> dist(n,0);
  q.push(src);
  dist[src] = 0;
  while(!q.empty())
  {
    int sz = q.size();
    for(int i=0;i<sz;i++)
    {
      int node = q.front();
      q.pop();

      for(auto nbr : adj[node])
      {
        if(!dist[nbr] && (nbr != src))
        {
          dist[nbr] = step;
          q.push(nbr);
        }
      }
    }
    step++;
  }

  for(auto it : dist)
  cout<<it<<" ";
}