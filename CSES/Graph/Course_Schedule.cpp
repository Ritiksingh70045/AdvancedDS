#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,m;
  cin>>n>>m;

  vector<int> indegree(n+1,0);
  vector<vector<int>> adj(n+1);
  for(int i=0;i<m;i++)
  {
    int a,b;
    cin>>a>>b;
    adj[a].push_back(b);
    indegree[b]++;
  }

  queue<int> q;
  for(int i=1;i<=n;i++)
  {
    if(indegree[i] == 0)
    q.push(i);
  }

  vector<int> ans;

  while(!q.empty())
  {
    int node = q.front();
    q.pop();

    ans.push_back(node);
    for(int nbr : adj[node])
    {
      indegree[nbr]--;
      if(indegree[nbr] == 0)
      q.push(nbr);
    }
  }

  if(ans.size() != n)
  cout<<"IMPOSSIBLE";
  else
  {
    for(auto it : ans)
    cout<<it<<" ";
  }
}