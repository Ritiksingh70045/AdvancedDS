class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def changeTree(self, root):
        if root is None:
            return

        child = 0
        if root.left:
            child += root.left.val
        if root.right:
            child += root.right.val

        if child >= root.val:
            root.val = child
        else:
            if root.left:
                root.left.val = root.val
            elif root.right:
                root.right.val = root.val

        self.changeTree(root.left)
        self.changeTree(root.right)

        tot = 0
        if root.left:
            tot += root.left.val
        if root.right:
            tot += root.right.val

        if root.left or root.right:
            root.val = tot


def inorderTraversal(root):
    if root is None:
        return
    inorderTraversal(root.left)
    print(root.val, end=" ")
    inorderTraversal(root.right)


root = TreeNode(3)
root.left = TreeNode(5)
root.right = TreeNode(1)
root.left.left = TreeNode(6)
root.left.right = TreeNode(2)
root.right.left = TreeNode(0)
root.right.right = TreeNode(8)
root.left.right.left = TreeNode(7)
root.left.right.right = TreeNode(4)

sol = Solution()

print("Binary Tree before modification:", end=" ")
inorderTraversal(root)
print()

sol.changeTree(root)

print("Binary Tree after Children Sum Property:", end=" ")
inorderTraversal(root)
print()
                           