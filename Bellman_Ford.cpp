#include <bits/stdc++.h>
using namespace std;

int main()
{
  int V = 6;
  int E = [ [ 3, 2, 6 ], [ 5, 3, 1 ], [ 0, 1, 5 ], [ 1, 5, -3 ], [ 1, 2, -2 ], [ 3, 4, -2 ], [ 2, 4, 3 ] ];
  int S = 0;

  vector<vector<pair<int,int>>> adj(V);
  for(auto it : E)
  {
    adj[it[0]].push_back({it[1] , it[2]});
  }
  vector<int> dist(V,1e9);

  dist[S] = 0;
  
}