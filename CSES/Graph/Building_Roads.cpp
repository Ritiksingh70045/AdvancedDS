#include <bits/stdc++.h>
using namespace std;

class DSU
{
private:
  vector<int> parent, size;

public:
  DSU(int n)
  {
    parent.resize(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
      parent[i] = i;
    }

    size.resize(n + 1, 1);
  }

  int findUPar(int node)
  {
    if (parent[node] == node)
      return parent[node];

    return parent[node] = findUPar(parent[node]);
  }

  void unite(int u, int v)
  {
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);

    if (ulp_u == ulp_v)
      return;

    if (size[ulp_u] <= size[ulp_v])
    {
      parent[ulp_u] = ulp_v;
      size[ulp_v] += size[ulp_u];
    }
    else
    {
      parent[ulp_v] = ulp_u;
      size[ulp_u] += size[ulp_v];
    }
  }
};

int main()
{
  int n, m;
  cin >> n >> m;
  DSU ds(n);
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;

    ds.unite(u, v);
  }
  set<int> need;
  for (int i = 1; i <= n; i++)
  {
    need.insert(ds.findUPar(i));
  }
  vector<int> v(need.begin(), need.end());
  cout << v.size() - 1 << '\n';
  for (int i = 0; i < v.size() - 1; i++)
  {
    cout << v[i] << " " << v[i + 1] << '\n';
  }
}