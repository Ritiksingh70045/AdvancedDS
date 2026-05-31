#include<bits/stdc++.h>
using namespace std;
int start_node;
int end_node;

bool cycle(int node , vector<int>& vis , vector<int>& pathVis , vector<int>& parent , vector<vector<int>>& adj)
{
  vis[node] = 1;
  pathVis[node] = 1;

  for(int nbr : adj[node])
  {
    if(!vis[nbr])
    {
      parent[nbr] = node;
      if(cycle(nbr,vis,pathVis,parent,adj))
      return true;
    }
    else if(pathVis[nbr])
    {
      start_node = nbr;
      end_node = node;
      return true;
    }
  }
  pathVis[node] = 0;
  return false;
}
int main()
{
  int n,m;
  cin>>n>>m;
  vector<vector<int>> adj(n+1);

  for(int i=0;i<m;i++)
  {
    int a,b;
    cin>>a>>b;

    adj[a].push_back(b);
  }

  vector<int> parent(n+1,-1);
  vector<int> vis(n+1 , 0);
  vector<int> pathVis(n+1,0); // optional
  bool ans = false;
  for(int i=1;i<=n;i++)
  {
    if(!vis[i])
    {
      ans = cycle(i,vis,pathVis,parent,adj);
      if(ans)
      break;
    }
  }
  if(!ans)
  cout<<"IMPOSSIBLE";
  else
  {
    vector<int> res;
    res.push_back(start_node);
    int curr = end_node;
    while(curr != start_node)
    {
      res.push_back(curr);
      curr = parent[curr];
    }
    res.push_back(start_node);

    reverse(res.begin() , res.end());
    cout<<res.size()<<'\n';
    for(auto it : res)
    cout<<it<<" ";
  }
}