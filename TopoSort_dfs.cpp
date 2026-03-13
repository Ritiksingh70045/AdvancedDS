#include<bits/stdc++.h>
using namespace std;
void solve(int node , vector<int>& vis , stack<int>& st , vector<vector<int>>& adj)
{
  vis[node] = 1;
  for(auto nbr : adj[node])
  {
    if(!vis[nbr])
    solve(nbr , vis , st , adj);
  }

  st.push(node);
}
int main()
{
  vector<vector<int>> adj(6);
  adj[0].push_back(1);
  adj[0].push_back(2);
  adj[1].push_back(3);
  adj[2].push_back(5);
  adj[3].push_back(4);
  adj[3].push_back(5);
  adj[4].push_back(5);
  
  vector<int> vis(6,0);
  stack<int> st;
  for(int i=0;i<6;i++)
  {
    if(!vis[i])
    solve(i,vis,st,adj);
  }

  vector<int> ans;
  while(!st.empty())
  {
    cout<<st.top()<<" ";
    st.pop();
  }

}