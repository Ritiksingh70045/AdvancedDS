#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int val;
  Node *left;
  Node *right;

  Node(int val = 0, Node *left = nullptr, Node *right = nullptr)
  {
    this.val = val;
    this.left = left;
    this->right = right;
  }
};

/*

                                                                    8
                                                                  /   \
                                                                5     12
                                                              /  \    / \
                                                              2    7  10 13
                                                            / \  / \
                                                            1  3 6   8
                                                                \
                                                                4

*/

Node* findRight(Node* root)
{
  if(root->right == nullptr)
  return root;

  return findRight(root->right);
}

Node* helper(Node* root)
{
  if(root->left)
  return root->right;
  if(root->right)
  return root->left;

  Node* rightChild = root->right;
  Node leftRightNode = findRight(root->left);
  leftRightNode->right = rightChild;
  return root->left;
}


void solve(Node* root , int target)
{
  if(root == NULL)
  return NULL;

  if(root->val == target)
  return NULL;

  while(root)
  {
    if(root->val > target)
    {
      if(root->left && (root->left->val == target))
      {
        root->left = helper(root->left);
        break;
      }
      else
      {
        root = root->left;
      }
    }
    else
    {
      if(root->right && (root->right->val == target))
      {
        root->right = helper(root->right);
        break;
      }
      else
      {
        root = root->right;
      }
    }
  }
}


int main()
{
  Node *root = new Node(8);

  root->left = new Node(5);
  root->right = new Node(12);

  // Left subtree
  root->left->left = new Node(2);
  root->left->right = new Node(7);

  root->left->left->left = new Node(1);
  root->left->left->right = new Node(3);

  root->left->left->right->right = new Node(4);

  root->left->right->left = new Node(6);
  root->left->right->right = new Node(8);

  // Right subtree
  root->right->left = new Node(10);
  root->right->right = new Node(13);

  int target = 5;
  Node* head = root;
  solve(root , target);
}