class Node:
  def __init__(self , val , left = None , right = None):
    self.val = val
    self.left = left
    self.right = right

def isSymm(l , r):
  if not l and not r:
    return True
  if not l or not r:
    return False
  
  return ((l.val == r.val)  and (isSymm(l.left , r.right)) and (isSymm(l.right , r.left)))

def solve(root):
  if not root:
    return False
  
  return isSymm(root.left , root.right)

root = Node(1)
root.left = Node(2)
root.right = Node(2)
root.left.left = Node(3)
root.left.right = Node(3)
root.right.left = Node(4)
root.right.right = Node(3)

print(solve(root))