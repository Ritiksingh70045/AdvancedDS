#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Function to find sum of weights of edges of the Minimum Spanning Tree.
  int spanningTree(int V, vector<vector<int>> adj[])
  {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> vis(V, 0);
    // {wt, node}
    pq.push({0, 0});
    int sum = 0;
    while (!pq.empty())
    {
      auto it = pq.top();
      pq.pop();
      int node = it.second;
      int wt = it.first;

      if (vis[node] == 1)
        continue;
      // add it to the mst
      vis[node] = 1;
      sum += wt;
      for (auto it : adj[node])
      {
        int adjNode = it[0];
        int edW = it[1];
        if (!vis[adjNode])
        {
          pq.push({edW, adjNode});
        }
      }
    }
    return sum;
  }
};

int main()
{

  int V = 5;
  vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
  vector<vector<int>> adj[V];
  for (auto it : edges)
  {
    vector<int> tmp(2);
    tmp[0] = it[1];
    tmp[1] = it[2];
    adj[it[0]].push_back(tmp);

    tmp[0] = it[0];
    tmp[1] = it[2];
    adj[it[1]].push_back(tmp);
  }

  Solution obj;
  int sum = obj.spanningTree(V, adj);
  cout << "The sum of all the edge weights: " << sum << endl;

  return 0;
}


//Time Complexity: O(E log E) where E is the number of edges and V is the number of vertices. This is because in the worst case, we will be adding all the edges to the priority queue and each insertion and deletion operation in the priority queue takes O(log V) time.

//! Note : in connected graph E <= V^2 so it might be written as ElogV as well. But in the worst case, it will be ElogE because we are sorting the edges based on their weights and in the worst case, we will be adding all the edges to the priority queue and each insertion and deletion operation in the priority queue takes O(log V) time.