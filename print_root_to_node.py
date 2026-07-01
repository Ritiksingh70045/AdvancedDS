class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


res = []

def solve(node, target, temp):
    global res

    if node is None:
        return

    temp.append(node.val)

    if node.val == target:
        res = list(temp)      # Copy the current path
        temp.pop()
        return

    solve(node.left, target, temp)
    solve(node.right, target, temp)

    temp.pop()


root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.right.left = Node(4)
root.right.right = Node(5)
root.right.left.left = Node(6)

target = 6

solve(root, target, [])

print(res)