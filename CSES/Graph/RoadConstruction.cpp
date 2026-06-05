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

    for (int i = 0; i <= n; i++)
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

  void unite(int u, int v)
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
  DSU ds(n);
  vector<pair<int, int>> mat;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    mat.push_back({u, v});
  }

  int component = n;
  int maxi = 1;

  for (auto it : mat)
  {
    int u = it.first;
    int v = it.second;

    if (ds.findUPar(u) != ds.findUPar(v))
    {
      ds.unite(u, v);

      component--;

      maxi = max(maxi, ds.size[ds.findUPar(u)]);
    }

    cout << component << " " << maxi << '\n';
  }
}