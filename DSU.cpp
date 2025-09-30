#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
  vector<int> parent, rank, size;

  DisjointSet(int n) {
    rank.resize(n + 1, 0);
    parent.resize(n + 1);
    size.resize(n + 1, 1); // Each node is initially its own component with size 1
    for (int i = 0; i <= n; i++) {
      parent[i] = i;
    }
  }

  int findUPar(int node) {
    if (node == parent[node])
      return node;
    return parent[node] = findUPar(parent[node]);
  }

  void unionByRank(int u, int v) {
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);
    if (ulp_u == ulp_v)
      return;

    if (rank[ulp_u] < rank[ulp_v]) {
      parent[ulp_u] = ulp_v;
    } else if (rank[ulp_v] < rank[ulp_u]) {
      parent[ulp_v] = ulp_u;
    } else {
      parent[ulp_u] = ulp_v;
      rank[ulp_v]++; // ✅ Fix: Increment rank
    }
  }

  void unionBySize(int u, int v) {
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);
    if (ulp_u == ulp_v)
      return;

    if (size[ulp_u] < size[ulp_v]) {
      parent[ulp_u] = ulp_v;
      size[ulp_v] += size[ulp_u]; // ✅ Fix: Add correct size
    } else {
      parent[ulp_v] = ulp_u;
      size[ulp_u] += size[ulp_v]; // ✅ Fix: Add correct size
    }
  }
};

int main() {
  DisjointSet ds(7);
  ds.unionBySize(1, 2);
  ds.unionBySize(3, 2);
  ds.unionBySize(5, 2);
  ds.unionBySize(4, 6);
  ds.unionBySize(4, 7);

  if (ds.findUPar(1) == ds.findUPar(7))
    cout << "Same Parent\n";
  else
    cout << "Different Parent\n";
}
