import sys
sys.setrecursionlimit(10**6)

MAXN = 100005
LOGN = 18

adj = [[] for _ in range(MAXN)]
lvl = [0] * MAXN
dp = [[0] * LOGN for _ in range(MAXN)]


def dfs(u, p):
    lvl[u] = lvl[p] + 1
    dp[u][0] = p

    for i in range(1, LOGN):
        dp[u][i] = dp[dp[u][i - 1]][i - 1]

    for v in adj[u]:
        if v == p:
            continue
        dfs(v, u)


def lca(u, v):
    if lvl[u] < lvl[v]:
        u, v = v, u

    diff = lvl[u] - lvl[v]

    for i in range(LOGN):
        if (diff >> i) & 1:
            u = dp[u][i]

    if u == v:
        return u

    for i in range(LOGN - 1, -1, -1):
        if dp[u][i] != dp[v][i]:
            u = dp[u][i]
            v = dp[v][i]

    return dp[u][0]


# Input
n, q = map(int, input().split())

for _ in range(n - 1):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)

lvl[0] = -1
dfs(1, 0)

for _ in range(q):
    u, v = map(int, input().split())
    print(lca(u, v))