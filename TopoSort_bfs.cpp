#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n = 6;
  vector<vector<int>> adj(n);

  adj[0].push_back(1);
  adj[0].push_back(2);
  adj[1].push_back(3);
  adj[2].push_back(5);
  adj[3].push_back(4);
  adj[3].push_back(5);
  adj[4].push_back(5);

  vector<int> indegree(n, 0);

  for (int i = 0; i < n; i++)
    for (auto it : adj[i])
      indegree[it]++;

  queue<int> q;

  for (int i = 0; i < n; i++)
    if (indegree[i] == 0)
      q.push(i);

  vector<int> ans;

  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    ans.push_back(node);

    for (auto nbr : adj[node])
    {
      indegree[nbr]--;
      if (indegree[nbr] == 0)
        q.push(nbr);
    }
  }

  if (ans.size() != n)
    cout << "Cycle detected\n";
  else
    for (auto it : ans)
      cout << it << " ";
}