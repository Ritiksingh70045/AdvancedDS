#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
    {
        TreeNode *successor = nullptr;

        while (root != nullptr)
        {
            if (p->val > root->val)
            {
                root = root->right;
            }
            else if (p->val < root->val)
            {
                successor = root;
                root = root->left;
            }
            else
            {
                if (root->right)
                {
                    root = root->right;
                    while (root->left)
                    {
                        root = root->left;
                    }
                    successor = root;
                }
                break;
            }
        }

        return successor;
    }

    TreeNode *inorderPredecessor(TreeNode *root, TreeNode *p)
    {
        TreeNode *predecessor = nullptr;

        while (root != nullptr)
        {
            if (p->val > root->val)
            {
                predecessor = root;
                root = root->right;
            }
            else if (p->val < root->val)
            {
                root = root->left;
            }
            else
            {
                if (root->left)
                {
                    root = root->left;
                    while (root->right)
                        root = root->right;
                    predecessor = root;
                }
                break;
            }
        }

        return predecessor;
    }
};

void printInOrder(TreeNode *root)
{
    if (root == nullptr)
        return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    cout << "BST: ";
    printInOrder(root);
    cout << endl;

    TreeNode *p = root->left->right;

    Solution solution;
    TreeNode *successor = solution.inorderSuccessor(root, p);
    TreeNode *predecessor = solution.inorderPredecessor(root, p);

    if (successor)
        cout << "Inorder Successor of " << p->val << " is: " << successor->val << endl;
    else
        cout << "Inorder Successor does not exist." << endl;

    if (predecessor)
        cout << "Inorder Predecessor of " << p->val << " is: " << predecessor->val << endl;
    else
        cout << "Inorder Predecessor does not exist." << endl;

    return 0;
}