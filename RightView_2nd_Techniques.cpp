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

vector<int> rightView(TreeNode *root)
{
  vector<int> ans;

  if (root == nullptr)
    return ans;

  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty())
  {
    int size = q.size();

    for (int i = 0; i < size; i++)
    {
      TreeNode *node = q.front();
      q.pop();

      // Last node of the current level
      if (i == size - 1)
        ans.push_back(node->data);

      if (node->left)
        q.push(node->left);

      if (node->right)
        q.push(node->right);
    }
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
  root->right->left = new TreeNode(9);
  root->right->right = new TreeNode(11);

  vector<int> ans = rightView(root);

  for (auto it : ans)
  {
    cout << it << " ";
  }

  return 0;
}