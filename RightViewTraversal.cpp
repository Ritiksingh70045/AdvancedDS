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
  map<int, pair<int, int>> mpp; // {x,{y,val}}
  queue<pair<TreeNode *, pair<int, int>>> q;
  q.push({root, {0, 0}}); // {node , {x , y}}

  while (!q.empty())
  {
    TreeNode *node = q.front().first;
    int x = q.front().second.first;
    int y = q.front().second.second;
    q.pop();
    if (mpp.find(x) != mpp.end())
    {
      if (y > mpp[x].first)
      {
        mpp[x].first = y;
        mpp[x].second = node->data;
      }
    }
    else
    {
      mpp[x].first = y;
      mpp[x].second = node->data;
    }

    if (node->left)
    {
      q.push({node->left, {x+1, y-1}});
    }
    if (node->right)
    {
      q.push({node->right, {x + 1, y + 1}});
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