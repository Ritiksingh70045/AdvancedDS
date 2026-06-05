#include <bits/stdc++.h>
using namespace std;

class DSU
{
public:
  vector<int> parent, size;

  DSU(int n)
  {
    parent.resize(n + 1);
    size.resize(n + 1, 1);

    for (int i = 1; i <= n; i++)
    {
      parent[i] = i;
    }
  }

  int findUPar(int node)
  {
    if (node == parent[node])
      return node;

    return parent[node] = findUPar(parent[node]);
  }

  void unionBySize(int u, int v)
  {
    u = findUPar(u);
    v = findUPar(v);

    if (u == v)
      return;

    if (size[u] < size[v])
      swap(u, v);

    parent[v] = u;
    size[u] += size[v];
  }
};

int main()
{
  int n, m;
  cin >> n >> m;

  vector<vector<long long>> edges;

  for (int i = 0; i < m; i++)
  {
    long long u, v, w;
    cin >> u >> v >> w;

    edges.push_back({w, u, v});
  }

  sort(edges.begin(), edges.end());

  DSU ds(n);

  long long mstCost = 0;
  int edgesUsed = 0;

  for (auto &it : edges)
  {
    long long w = it[0];
    int u = it[1];
    int v = it[2];

    if (ds.findUPar(u) != ds.findUPar(v))
    {
      ds.unionBySize(u, v);

      mstCost += w;
      edgesUsed++;
    }
  }

  if (edgesUsed != n - 1)
  {
    cout << "IMPOSSIBLE";
  }
  else
  {
    cout << mstCost;
  }

  return 0;
}