#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> topoSort(int V, vector<int> adj[])
  {

    vector<int> ans;

    vector<int> inDegree(V, 0);

    for (int i = 0; i < V; i++)
    {
      for (auto it : adj[i])
        inDegree[it]++;
    }

    queue<int> q;

    for (int i = 0; i < V; i++)
    {
      if (inDegree[i] == 0)
        q.push(i);
    }

    while (!q.empty())
    {
      int node = q.front();

      ans.push_back(node);
      q.pop();

      for (auto it : adj[node])
      {

        inDegree[it]--;

        if (inDegree[it] == 0)
          q.push(it);
      }
    }

    return ans;
  }
};

int main()
{

  int V = 6;
  vector<int> adj[V] = {
      {},
      {},
      {3},
      {1},
      {0, 1},
      {0, 2}};

  Solution sol;

  vector<int> ans = sol.topoSort(V, adj);

  cout << "The topological sorting of the given graph is: \n";
  for (int i = 0; i < V; i++)
  {
    cout << ans[i] << " ";
  }

  return 0;
}