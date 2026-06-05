class DSU:
  def __init__(self,n):
    self.parent = list(range(n+1))
    self.size = [1]*(n+1)
  
  def findUPar(self,node):
    if node == self.parent[node]:
      return node
    
    self.parent[node] = self.findUPar(self.parent[node])
    return self.parent[node]
  
  def unite(self,u,v):
    u = self.findUPar(u)
    v = self.findUPar(v)
    
    if u == v:
      return
    
    if self.size[u] < self.size[v]:
      u,v = v,u
      
    self.parent[v] = u
    self.size[u] += self.size[v]
    
if __name__ == '__main__':
  n,m = map(int , input().split())
  ds = DSU(n)
  
  roads = []
  for _ in range(m):
    u,v = map(int , input().split())
    roads.append((u,v))
    
  components = n
  maxi = 1
  
  for u,v in roads:
      if ds.findUPar(u) != ds.findUPar(v):
        ds.unite(u,v)
      
        components -= 1
        maxi = max(maxi , ds.size[ds.findUPar(u)])
      print(components , maxi)