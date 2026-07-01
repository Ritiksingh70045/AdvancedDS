class Node:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

ans = True

def solve(node):
    global ans

    if node is None:
        return 0

    l = solve(node.left)
    r = solve(node.right)

    if abs(l - r) > 1:
        ans = False

    return 1 + max(l, r)


root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.right.left = Node(4)
root.right.right = Node(5)

solve(root)

print(ans)