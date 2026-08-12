#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  // DFS on original graph
  // Store nodes according to finishing time
  void dfs1(int node, vector<int> adj[], vector<int> &vis, stack<int> &st)
  {
    vis[node] = 1;

    for (int nei : adj[node])
    {
      if (!vis[nei])
      {
        dfs1(nei, adj, vis, st);
      }
    }

    // Push after all neighbours are processed
    st.push(node);
  }

  // DFS on transposed graph
  void dfs2(int node, vector<int> adjT[], vector<int> &vis)
  {
    vis[node] = 1;

    for (int nei : adjT[node])
    {
      if (!vis[nei])
      {
        dfs2(nei, adjT, vis);
      }
    }
  }

public:
  int kosaraju(int V, vector<int> adj[])
  {

    // --------------------------------
    // STEP 1: DFS + Finishing Time
    // --------------------------------

    vector<int> vis(V, 0);
    stack<int> st;

    for (int i = 0; i < V; i++)
    {
      if (!vis[i])
      {
        dfs1(i, adj, vis, st);
      }
    }

    // --------------------------------
    // STEP 2: Reverse / Transpose Graph
    // --------------------------------

    vector<int> adjT[V];

    for (int u = 0; u < V; u++)
    {

      // Reset visited array
      vis[u] = 0;

      for (int v : adj[u])
      {
        // Original: u -> v
        // Transpose: v -> u
        adjT[v].push_back(u);
      }
    }

    // --------------------------------
    // STEP 3: DFS in decreasing
    //         finishing time
    // --------------------------------

    int scc = 0;

    while (!st.empty())
    {

      int node = st.top();
      st.pop();

      if (!vis[node])
      {

        // One complete DFS = one SCC
        scc++;

        dfs2(node, adjT, vis);
      }
    }

    return scc;
  }
};

int main()
{

  int V = 5;

  vector<vector<int>> edges = {
      {1, 0},
      {0, 2},
      {2, 1},
      {0, 3},
      {3, 4}};

  vector<int> adj[V];

  for (auto edge : edges)
  {
    int u = edge[0];
    int v = edge[1];

    adj[u].push_back(v);
  }

  Solution obj;

  cout << "Number of SCCs: "
       << obj.kosaraju(V, adj)
       << endl;

  return 0;
}