#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
  int data;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> solve(TreeNode *root)
{
  map<int, pair<int, int>> mpp; // {y,{x,val}}
  queue<pair<TreeNode *, pair<int, int>>> q;
  q.push({root, {0, 0}}); // {node , {y , x}}

  while (!q.empty())
  {
    TreeNode *node = q.front().first;
    int y = q.front().second.first;
    int x = q.front().second.second;
    q.pop();
    if (mpp.find(y) != mpp.end())
    {
      if (x < mpp[y].first)
      {
        mpp[y].first = x;
        mpp[y].second = node->data;
      }
    }
    else
    {
      mpp[y].first = x;
      mpp[y].second = node->data;
    }

    if (node->left)
    {
      q.push({node->left, {y - 1, x + 1}});
    }
    if (node->right)
    {
      q.push({node->right, {y + 1, x + 1}});
    }
  }
  vector<int> ans;
  for(auto p : mpp)
  {
    ans.push_back(p.second.second);
  }
  return ans;
}

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(10);
  root->left->left->right = new TreeNode(5);
  root->left->left->right->right = new TreeNode(6);
  root->right = new TreeNode(3);
  root->right->right = new TreeNode(11);
  root->right->left = new TreeNode(9);

  vector<int> res = solve(root);
  for(auto it : res)
  {
    cout<<it<<" ";
  }
}