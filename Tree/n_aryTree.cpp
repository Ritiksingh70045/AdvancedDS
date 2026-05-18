#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int val;
  vector<Node *> children;

  Node(int _val)
  {
    this->val = _val;
  }
};

Node *build(int u, unordered_map<int, vector<int>> &adj)
{
  Node *root = new Node(u);

  for (int v : adj[u])
  {
    root->children.push_back(build(v, adj));
  }

  return root;
}

void dfs(Node *root)
{
  if (!root)
    return;

  cout << root->val << " ";

  for (auto node : root->children)
  {
    dfs(node);
  }
}

int main()
{
  unordered_map<int, vector<int>> adj;

  /*
          1
       /  |  \
      2   3   4
         / \   \
        5   6   7
           /
          8
  */

  adj[1] = {2, 3, 4};
  adj[3] = {5, 6};
  adj[4] = {7};
  adj[6] = {8};

  Node *root = build(1, adj);

  dfs(root);
}