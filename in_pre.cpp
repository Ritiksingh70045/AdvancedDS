#include <bits/stdc++.h>
using naespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
  unordered_map<int,int> in;
  int n = inorder.size();
  for(int i=0;i<n;i++)
  {
    in[inorder[i]] = i;
    
  }
}
int main()
{
  vector<int> inorder = {4, 2, 1, 5, 6, 3};
  vector<int> preorder = {1, 2, 4, 3, 5, 6};
  TreeNode *root = buildTree(preorder, inorder);
}